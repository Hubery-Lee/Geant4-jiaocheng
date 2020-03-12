---
title: Emacs yasnippets and markdown configure
date: 2018-10-11 22:07:58
categories: 编程工具学习与应用
tags: [Emacs24.3, markdown]
description: Focus on how to use emacs to edit markdown scripts.
password:
---

@[TOC](emacs yasnippets 和makrdown的配置)
## yasnippets 的配置
-  安装

```lisp
cd ~/.emacs.d/site-lisp
git clone https://github.com/capitaomorte/yasnippet
```
- 配置==init.el==
```lisp
(add-to-list 'load-path
              "~/.emacs.d/site-lisp/yasnippet")
(require 'yasnippet)
(setq yas-snippet-dirs
      '("~/.emacs.d/snippets" ;; personal snippets
        ))
(yas-global-mode 1)
```
- 添加自定义模板

   M-x yas-new-snippet 创建新模板
   C-c C-c 保存

- 模板内容说明

 contributor: snippet作者名称及电邮
snippet的语法变量是以$美元符开始的，根据变量$1 $2 $... 定义顺序光标移动位置，特殊的$0是最后光标停位置，语法${N:default value}。

## markdown 的配置

- [参看这篇文章](https://blog.csdn.net/csdnmonkey/article/details/54934663)
google markdown emacs 配置
https://linuxtoy.org/archives/emacs-markdown-mode.html

- 重点看下面这个，此为产品原网址。该网站介绍了产品的多种安装方式。
google markdown-mode
==http://jblevins.org/projects/markdown-mode/==  

- 常用命令
* `C-c C-c m: markdown-command` > ` *markdown-output*` buffer.
* `C-c C-c p: markdown-command `> temporary file> browser.
* `C-c C-c e: markdown-command` > `basename.html`.
* `C-c C-c v: markdown-command` > `basename.html` > browser.
* `C-c C-c w: markdown-command` > kill ring.
* `C-c C-c o: markdown-open-command`.
* `C-c C-c l: markdown-live-preview-mode` >` *eww*` buffer.





## 参考资料

[1] https://www.cnblogs.com/liweilijie/archive/2012/12/30/2840081.html
[2] https://www.douban.com/note/551980740/
[3] https://blog.csdn.net/csdnmonkey/article/details/54934663
[4] https://jblevins.org/projects/markdown-mode/
