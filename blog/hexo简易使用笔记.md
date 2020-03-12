---
title: hexo简易使用笔记
date: 2018-09-01 10:23:42
tags: [hexo]
categories: 编程工具学习与应用
description: use hexo to deploy your blog
---

## 常用命令

``` bash
hexo new "postName" #新建文章
hexo new page "pageName" #新建页面
hexo generate #生成静态页面至public目录
hexo server #开启预览访问端口（默认端口4000，'ctrl + c'关闭server）
hexo deploy #部署到GitHub
hexo help  # 查看帮助
hexo version  #查看Hexo的版本

```

## 缩写

``` bash
hexo n == hexo new
hexo g == hexo generate
hexo s == hexo server
hexo d == hexo deploy
```

## 组合命令
``` bash
hexo s -g #生成并本地预览
hexo d -g #生成并上传
```

## hexo发布博客预览

本地预览

``` bash
hexo s -g #生成并本地预览
```
然后，在浏览器中打开 http://localhost:4000/

发布到github绑定的个人博客网页上

``` bash
hexo d -g #生成并上传
```
比如，我发布博客后，就直接可以采用个人网络域名访问 http://lihui-snippets.cn/ 

具体github+hexo如何搭建个人博客教程可以百度以下；我觉得这篇博客写的比较好 https://www.cnblogs.com/liuxianan/p/build-blog-website-by-hexo-github.html#%E4%BD%BF%E7%94%A8hexo%E5%86%99%E5%8D%9A%E5%AE%A2




