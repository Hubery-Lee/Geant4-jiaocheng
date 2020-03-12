---
title: LeeEmacs-setting
date: 2018-09-01 01:19:16
categories: 编程工具学习与应用
tags: [Emacs24.3]
description: personal customization for emacs 24
---

## 模块功能yasnippet

1. 下载yasnippet安葬包，加压到~/.emacs.d/plugins目录下
2. 在～/.emacs文件中配置yasnippet

``` bash
;; add yasnippet plugin 
(add-to-list 'load-path
              "~/.emacs.d/plugins/yasnippet")
(require 'yasnippet)
(yas-global-mode 1)


;;代码折叠
(load-library "hideshow")
(add-hook 'java-mode-hook 'hs-minor-mode)
(add-hook 'perl-mode-hook 'hs-minor-mode)
(add-hook 'php-mode-hook 'hs-minor-mode)
(add-hook 'emacs-lisp-mode-hook 'hs-minor-mode)
(add-hook 'c++-mode-hook 'hs-minor-mode)
(add-hook 'c-mode-hook 'hs-minor-mode)
(add-hook 'matlab-mode-hook 'hs-minor-mode)
(add-hook 'fortran-mode-hook 'hs-minor-mode)
(add-hook 'f90-mode-hook 'hs-minor-mode)
(add-hook 'markdown-mode-hook 'hs-minor-mode)
(add-hook 'org-mode-hook 'hs-minor-mode)
```

## 文件头个人信息设置——header2.el

1. wiki 下载header2.el
2. 将header2.el 放到~/.emacs.d/plugins文件夹下；
3. 在～/.emacs文件中配置个人信息

``` bash
;;====================info of user====================
;;********************header**************************
;;(load-file "~/.emacs.d/header2.el")
(add-to-list 'load-path "~/.emacs.d/plugins" )
;; 设置文件头中的姓名
(require 'header2)
(setq user-full-name "Li Hui")

;; 设置邮箱
(setq user-email-address "h*****@126.com")

 
;; 设置每次保存时要更新的项目
(autoload 'auto-update-file-header "header2")
(add-hook 'write-file-hooks 'auto-update-file-header)
(autoload 'auto-make-header "header2")
(add-hook 'emacs-lisp-mode-hook 'auto-make-header)
(add-hook 'c-mode-common-hook   'auto-make-header) 
(add-hook 'c++-mode-common-hook   'auto-make-header)
(add-hook 'text-mode-hook   'auto-make-header)

;;(add-hook 'make-header-hook 'header-shell nil t) 
```

## 自动补全 auto-complete

经过尝试，直接解压到~/.emacs.d/plugins文件夹然后make 和make install 然后在.emacs文件配置导入auto-complete插件，但并不能实现自动补全功能。但也没有报错；我认为可能是由于可能式auto-complete没有开启的缘故；

1. 检测auto-complete有没有安装成功的方法

``` bash
安装完后，重启emacs然后输入ac，若出现可选的自动补全选项，那么说明已经安装成功了；
```

2. auto-complete的安装方法——第二种安装成功
（1）传统方法是采用解压到~/.emacs.d/plugins,然后make和make install，再在.emacs中进行配置

``` bash
(add-to-list 'load-path "/home/hubery_lee/.emacs.d/plugins/auto-complete")
(require 'auto-complete-config)
(add-to-list 'ac-dictionary-directories "/home/hubery_lee/.emacs.d/plugins/auto-complete/ac-dict")
(ac-config-default)
```
（2）通过MELPA或MELPA Stable的package.el安装auto-complete.el；
参考github这个开放者介绍的方法进行安装 https://github.com/auto-complete/auto-complete/blob/master/doc/manual.md

首先，添加melpa或melpa-stable的package库

``` bash
(require 'package)

;; If you want to use latest version
(add-to-list 'package-archives '("melpa" . "https://melpa.org/packages/"))

;; If you want to use last tagged version
(add-to-list 'package-archives '("melpa-stable" . "https://stable.melpa.org/packages/"))
(package-initialize)
```
然后,利用package功能安装auto-complete

``` bash
在emacs的minibuffer里选取以下一种命令安装auto-complete
    M-x package-list-packages and select auto-complete
    M-x package-refresh-contents and M-x package-install auto-complete
```
最后，根据显示的安装路径，在.emacs中进行配置

``` bash
;; add auto-complete plugin

(add-to-list 'load-path 
	"/home/hubery_lee/.emacs.d/elpa/auto-complete-20170125.245")
(require 'auto-complete-config)
(add-to-list 'ac-dictionary-directories "/home/hubery_lee/.emacs.d/elpa/auto-complete-20170125.245/ac-dict")
(ac-config-default)
```

## 自定义小功能

``` bash

;;显示匹配的括号
(show-paren-mode t) 

;;光标显示为一竖线
(setq-default cursor-type 'bar)

;;setting frame title 
(setq frame-title-format "%b - LiHui@CIRP")

;;鼠标指针避光标
(mouse-avoidance-mode 'animate)

;;不生成临时文件
(setq-default make-backup-files nil)
;;允许emacs和外部其他程序的粘贴
(setq x-select-enable-clipboard t)
;;使用鼠标中键可以粘贴
(setq mouse-yank-at-point t)
;; 自动的在文件末增加一新行
;;(setq require-final-newline t)
;; 当光标在行尾上下移动的时候，始终保持在行尾。

;;color
;;(add-to-list 'load-path "~/.emacs.d/plugins")
;;(require 'color-theme)
;;(color-theme-subtle-hacker)
;;(color-theme-xemacs)
;;(color-theme-wheat)
;;(color-theme-calm-forest)
;;(color-theme-matrix)
;;(color-theme-robin-hood)
;;(color-theme-euphoria)
;;(color-theme-arjen)
;;(color-theme-jsc-dark)

;;hide tool bar
(tool-bar-mode 0)

;; show line number
(global-linum-mode 'linum-mode)  
```

