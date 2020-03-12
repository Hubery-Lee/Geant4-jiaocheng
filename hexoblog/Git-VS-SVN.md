---
title: Git-VS-SVN
date: 2018-08-20 00:14:35
categories: 编程工具学习与应用
tags: [git,svn]
description: Git和svn均是版本控制软件，两者的主要区别是Git是分布式管理的版本控制器，SVN（Subversion）是集中式管理的版本控制器

---

## Git和SVN主要差别

SVN只有一个单一的集中管理的服务器，保存所有文件的修订版本，而协同工作的人们都通过客户端连到这台服务器，取出最新的文件或者提交更新。
Git每一个终端都是一个仓库，客户端并不只提取最新版本的文件快照，而是把原始的代码仓库完整地镜像下来。每一次的提取操作，实际上都是一次对代码仓库的完整备份。Git不仅仅是个版本控制系统，它也是个内容管理系统（CMS），工作管理系统等。

### 1.分布式VS集中式版本控制

svn采用集中式版本控制

{% asset_img 20161214020406505.jpg svn集中式版本控制 %}

git采用分布式版本控制

{% asset_img 20161214020603227.jpg git分布式版本控制 %}

两种版本控制的区别：
（1）svn 过渡依赖中央服务器，出现故障影响其他工作;git中央服务器只用于方便交流，有没有中央服务器都行；
（2）svn 版本库只保存在中央服务器，本地检测时不会检出版本库；git每个本地电脑均会保存完整的版本库；
（3）svn 的commit依赖连接中央服务器的网络；git由于有本地版本库，可以commit不依赖网络，commit可以频繁使用；git 通过push来实现其他电脑的版本库的同步（synchronize）操作；

### 2.分支功能

（1）svn 创建分支就是创建了一个新文件夹并拥有实际的文件，类似于拷贝了一份源文件，相当于在服务器上创建了分支，会影响到连接服务器的所有本地工作副本；git创建分支并没有创建文件夹，创建分支只是多了一个索引文件，并记录这个分支的变化，占用空间小，分支之间可以自由切换互不影响。
（2）git具有代码审核功能，各个成员请求将自己的分子合并到主分支均需要管理人员进行审核。
git的工作流程如下：


{% asset_img gitProcess.png gitprocess %}

### 3.git的使用

（1）安装配置
（2）pc上任意获取，运行git clone url，将远程版本库克隆到本地
（3）日常场景

{% asset_img 20180227165834705.png 日常使用 %}

a.创建一个新文件，并添加到版本库中使用命令：
创建了一个新文件，需要添加到版本库里（追踪此文件）使用git add filename命令，我想保存一下，使用git commit -m ..... 我想把我改变的推送给其他人（服务器）git push -u origin master(提交代码)。
``` bash
$ mkdir newDoc
$ git add newDoc
```
b.保存一下修改记录
``` bash
$ git commit -m "提交添加一个新文件到版本库"  #“”内为chang messages
```
c.将我的修改推送给其他人或服务器
``` bash
$ git push -u origin master
```
我想把别人改变的代码拉去过来其实有两种方法git fetch与git pull。它们都是将从服务器上拉取最新的代码。那么它们什么区别呢？Git fetch 是仅仅将代码拉取下来，而git pull 不仅将服务器上的代码拉去下来，而且进行了合并merge。总结一下就是git pull 包含了 git fetch + merge。

d.将别人的代码拉取过来
``` bash
$ git pull
```
我想把别人改变的代码拉去过来其实有两种方法git fetch与git pull。它们都是将从服务器上拉取最新的代码。那么它们什么区别呢？Git fetch 是仅仅将代码拉取下来，而git pull 不仅将服务器上的代码拉去下来，而且进行了合并merge。总结一下就是git pull 包含了 git fetch + git merge。

e.删除原来的文件
``` bash
$ git rm file #将会将file文件从暂存区与磁盘删除
```
原来的有个文件，想删除了，使用git rm file(停止追踪文件并从磁盘上删除),如果我们只想将 停止追踪文件，但是不删除只需要 git rm --cached <file>。然后想把这个改变推送给别人，就应该是用git commit 然后git push 将自己的改变推送到git服务器。

f.git分支功能的使用
那么平时我们收到一个新功能的任务，应该是怎样的操作呢？比较正确的操作流程应该是这样，我们先使用git branch 查看一下我们本地到底有多少分支，然后我们先使用git branch <new branch>从develop分支新建一个分支featureN,然后使用git checkout <branch/tag> 切换到新建的featureN分支里。在新的分支里进行新功能开发。
``` bash
$ git branch #查看分支
$ git branch #新建分支featureN 即 <new branch>
$ git checkout <branch/tag> #切换到新建的featureN分支里，在新的分支里进行新功能的开发。
```
g.恢复到某一时刻
我们在进行新功能开发的时候，每实现一个小功能的时候，我们就git commit 进行提交一下，刚提交完，突然发现，这次提交的东西会严重影响其他功能，想撤销这次提交，我们需要使用git reset --hart HEAD 来撤销工作目录中所有未提交文件的修改内容。那么如果我们想撤销指定的一次提交呢？我们需要使用git revert <commit> 进行指定的提交。
``` bash
$ git reset HEAD #撤回暂存中未提交的内容
$ git revert <commit> #撤回一次指到定的提交
```

h.分支的合并
假设开发完毕后，应该怎么做？对，就是将新功能的分支合并到develop分支里。就是先切换到develop分支里，然后使用git merge 命令进行合并。这时，新功能开发完毕，新建的featureN分支就没用了，我们使用git branch -d <branch>将无用的分支删除。至此，我们新功能开发完毕。
``` bash
$ git merge 
$ git branch -d <branch>
```

i.查看工作日志
``` bash
$ git log
```
Git log 作用很大，功能也很多
