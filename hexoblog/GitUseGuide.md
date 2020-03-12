---
title: Git简易使用笔记
date: 2018-09-01 18:49:17
tags: [git]
categories: 编程工具学习与应用
description: how to use of git
---


## 创建仓库

采用git init 在目录创建新的仓库

``` bash
$ mkdir newrepository  #
$ cd newrepository
$ git init
```

或者直接采用 git init 仓库名

``` bash
$ git init newrepository
```

## 软件仓库下载

下载仓库 git clone 拷贝到本地
``` bash
$ get clone [url]
```
例如，从我的github上下载代码到本地
``` bash
$ get clone https://github.com/Hubery-Lee/LeeEmacs-setting
```

## 软件仓库的快照

### git的日常使用

git 的日常使用过程

{% asset_img 1.jpg 日常使用原理 %}

git add 命令可将文件添加到缓存()
git status 查看添加到缓存的文件状态 -s 简短结果输出

``` bash
$ touch README
$ touch hello.php
$ ls
README        hello.php
$ git status -s
?? README
?? hello.php

$ git add README hello.php 

$ git status -s
A  README
A  hello.php
$ 

在 README 添加以下内容：# Runoob Git 测试，然后保存退出。

$ echo "# Runoob Git">>README 
$ git status -s
AM README
A  hello.php

$ git add .
$ git status -s
A  README
A  hello.php

```

执行 git diff 来查看执行 git status 的结果的详细信息。

git diff 命令显示已写入缓存与已修改但尚未写入缓存的改动的区别。git diff 有两个主要的应用场景。

    尚未缓存的改动：git diff
    查看已缓存的改动： git diff --cached
    查看已缓存的与未缓存的所有改动：git diff HEAD
    显示摘要而非整个 diff：git diff --stat

git status 显示你上次提交更新后的更改或者写入缓存的改动， 而 git diff 一行一行地显示这些改动具体是啥。

接下来我们来查看下 git diff --cached 的执行效果：

``` bash
在 hello.php 文件中输入以下内容：
<?php
echo '菜鸟教程：www.runoob.com';
?>

$ git status -s
A  README
AM hello.php
$ git diff
diff --git a/hello.php b/hello.php
index e69de29..69b5711 100644
--- a/hello.php
+++ b/hello.php
@@ -0,0 +1,3 @@
+<?php
+echo '菜鸟教程：www.runoob.com';
+?>

$ git add hello.php 
$ git status -s
A  README
A  hello.php
$ git diff --cached
diff --git a/README b/README
new file mode 100644
index 0000000..8f87495
--- /dev/null
+++ b/README
@@ -0,0 +1 @@
+# Runoob Git 测试
diff --git a/hello.php b/hello.php
new file mode 100644
index 0000000..69b5711
--- /dev/null
+++ b/hello.php
@@ -0,0 +1,3 @@
+<?php
+echo '菜鸟教程：www.runoob.com';
+?>

```

git commit 将缓存区内容添加到仓库中
``` bash
 配置用户名和邮箱地址
$ git config --global user.name 'runoob'
$ git config --global user.email test@runoob.com
```
提交缓存到仓库
``` bash
$ git commit -m '第一次版本提交'
[master (root-commit) d32cf1f] 第一次版本提交
 2 files changed, 4 insertions(+)
 create mode 100644 README
 create mode 100644 hello.php

$ git status
# On branch master
nothing to commit (working directory clean)
```

git reset HEAD 命令用于取消已缓存的内容。
同时修改README和hello.php,然后撤销hello.php的缓存
``` bash
$ git status -s
 M README
 M hello.php
$ git add .
$ git status -s
M  README
M  hello.pp
$ git reset HEAD hello.php 
Unstaged changes after reset:
M    hello.php
$ git status -s
M  README
 M hello.php

$ git commit -m '修改'
[master f50cfda] 修改
 1 file changed, 1 insertion(+)
$ git status -s
 M hello.php
```
仍然可以再次提交hello.php修改的内容
``` bash
$ git commit -am '修改 hello.php 文件'
[master 760f74d] 修改 hello.php 文件
 1 file changed, 1 insertion(+)
$ git status
On branch master
nothing to commit, working directory clean
```

简而言之，执行 git reset HEAD 以取消之前 git add 添加，但不希望包含在下一提交快照中的缓存。

git rm
如果只是简单地从工作目录中手工删除文件，运行 git status 时就会在 Changes not staged for commit 的提示。

``` bash
$ git rm <file>
$ git rm -f  <file>
$ git rm -r <file>
$ git rm --cached <file>
类似有git mv 移动和重命名
$ git mv README  README.md
```
要从 Git 中移除某个文件，就必须要从已跟踪文件清单中移除，然后提交。可以用以下命令完成此项工作



### git中tag和branch的使用


{% asset_img 2.png tag和branch %}

创建分支、列出分支、切换分支、删除分支
``` bash
$ git branch testing #创建testing分支
$ git branch   #列出分支
* master
  testing

$ git checkout testing
Switched to branch 'testing'

$ git checkout master
Switched to branch 'master'

$ git checkout -b newtest  #创建newtest分支并切换到该分支
Switched to a new branch 'newtest'

$ git branch -d testing  #删除testing分支
Deleted branch testing (was 85fc7e7).

$ git branch  
* master
  newtest

$ git merge newtest     #将newtest分支合并到master分支
Updating 2e082b7..556f0a0
Fast-forward
 test2.txt | 1 -
 1 file changed, 1 deletion(-)
 delete mode 100644 test2.txt
```

当同时记录到master的修改和branch分支的修改时，会出现合并分支冲突
手动修改冲突部分
采用git add 告诉git文件冲突已经解决；
``` bash
$ git merge change_site
Auto-merging test.txt
CONFLICT (content): Merge conflict in test.txt
Automatic merge failed; fix conflicts and then commit the result.
$ cat test.txt 
<<<<<<< HEAD
runoob.com
新增加一行
=======
www.runoob.com
>>>>>>> change_site

$ vim test.txt 
$ cat test.txt 
www.runoob.com
新增加一行
$ git diff
diff --cc test.txt
index f84c2a4,bccb7c2..0000000
--- a/test.txt
+++ b/test.txt
@@@ -1,2 -1,1 +1,2 @@@
- runoob.com
+ www.runoob.com
 +新增加一行

$ git status -s
UU test.txt
$ git add test.txt 
$ git status -s
M  test.txt
$ git commit
[master 88afe0e] Merge branch 'change_site'

```

查看提交历史
``` bash
$ git log  #详细提交历史
$ git log --oneline  #简洁提交历史
$ git log --oneline --graph  #--graph开启了拓扑图选项
$ git log --reverse --oneline #用 '--reverse'参数来逆向显示所有日志。
$ git log --author=Linus --oneline -5 #--author查找指定用户提交的记录
$ git log --oneline --before={3.weeks.ago} --after={2010-04-18} --no-merges#指定日期，可以执行几个选项：--since 和 --before，但是你也可以用 --until 和 --after --no-merges 选项以隐藏合并提交

```

标签
写一句标签注解，就像你给提交写注解一样。
``` bash
$ git tag -a v1.0 
$ git log --oneline --decorate --graph  #执行 git log --decorate 时，可以看到标签
$ git tag -a v0.9 85fc7e7       #给提交代码85fc7e7追加标签
$ git log --oneline --decorate --graph
*   88afe0e (HEAD, tag: v1.0, master) Merge branch 'change_site'
|\  
| * d7e7346 (change_site) changed the site
* | 14b4dca 新增加一行
|/  
* 556f0a0 removed test2.txt
* 2e082b7 add test2.txt
* 048598f add test.txt
* 85fc7e7 (tag: v0.9) test comment from runoob.com

$ git tag  #查看所有标签
v0.9
v1.0

$ git tag -a <tagname> -m "runoob.com标签"  #指定标签信息命令
$ git tag -s <tagname> -m "runoob.com标签"  #PGP签名标签命令
```

## 远程软件仓库的提取

``` bash
$ git remote   #查看远程仓库
origin
$ git remote -v  #-v 参数，可以看到每个别名的实际链接地址。
origin    git@github.com:tianqixin/runoob-git-test.git (fetch)
origin    git@github.com:tianqixin/runoob-git-test.git (push)

$ git fetch [alias] #从远程仓库下载分支和数据
$ git fetch origin  #从远程仓库下载origin分支和数据
remote: Counting objects: 3, done.
remote: Compressing objects: 100% (2/2), done.
remote: Total 3 (delta 0), reused 0 (delta 0), pack-reused 0
Unpacking objects: 100% (3/3), done.
From github.com:tianqixin/runoob-git-test
   0205aab..febd8ed  master     -> origin/master
```


## 远程软件仓库的上传
``` bash
$ git merge [alias]/[branch] #以将服务器上的任何更新合并到你的当前分支
$ git merge origin/master  #从远端仓库提取数据并尝试合并到当前分支
Updating 0205aab..febd8ed
Fast-forward
 README.md | 1 +
 1 file changed, 1 insertion(+)

$ git push [alias] [branch] #推送你的新分支与数据到某个远端仓库
$ git push origin master    # 推送到 Github

git remote rm  [alias]
git remote mv [aliasA] [aliasB]

```

## 获取软件仓库更改历史

``` bash

$ git status
$ git status -s
$ git diff 
$ git diff --cached
$ git log  #详细提交历史
$ git log --oneline  #简洁提交历史
$ git log --oneline --graph  #--graph开启了拓扑图选项
$ git log --reverse --oneline #用 '--reverse'参数来逆向显示所有日志。
$ git log --author=Linus --oneline -5 #--author查找指定用户提交的记录
$ git log --oneline --before={3.weeks.ago} --after={2010-04-18} --no-merges#指定日期，可以执行几个选项：--since 和 --before，但是你也可以用 --until 和 --after --no-merges 选项以隐藏合并提交

$ git branch
$ git tag
$ git remote

```

## 回滚到软件仓库的历史版本

``` bash
$ git reset 
$ git reset HEAD [file]
$ git reset --hard <target_commit_id>
$ git reset --soft origin/source 命令（source 分支）
```





