---
title: Hexo Next theme Setting
date: 2018-09-14 18:16:57
categories: 编程工具学习与应用
tags: [hexo]
description: 本文介绍如何配置Next主题；其中，以下功能待补充：文章版权声明、文章加密访问、字数、时长、访问量、侧边栏社交小图标设置、设置网站图标、评论功能插件配置、主题配色、站外分享、头部顶栏背景颜色或图片设置、页脚设置
---

[referrence site1](http://theme-next.iissnan.com)
[referrence site2](https://blog.csdn.net/w_ngzeqi/article/details/73863543)  文章版权声明、文章加密访问、字数、时长、访问量 [another site](https://www.jianshu.com/p/1ff2fcbdd155)
[referrence site3](https://blog.csdn.net/qq_32454537/article/details/79482896) 侧边栏社交小图标设置、设置网站图标、评论功能插件配置
[referrence site3](https://blog.csdn.net/manmandong123/article/details/80739126) 添加评论功能[another site](https://blog.csdn.net/qq_32454537/article/details/79482879)
[Somebody's blog Note](https://blog.csdn.net/lanuage/article/details/78991798) 站外分享 [another site](https://asdfv1929.github.io/categories/GitBlog/)
[referrence sit4](https://blog.csdn.net/qq_30242609/article/details/54799019) 修改主题配色


对于文章版权声明功能，可以直接去next主题下的`_config.yml`中开启，个人认为抱着开源开放特性，这个功能并不是很重要；

## 设置版权信息

1.在next主题下的next/_config.yml中设置copyright;
``` bash
# Declare license on posts
post_copyright:
  enable: true
  license: CC BY-NC-SA 3.0
  license_url: #https://creativecommons.org/licenses/by-nc-sa/3.0/
```
在hexo站点配置文件_config.yml中设置url;
``` bash
# URL
## If your site is put in a subdirectory, set url as 'http://yoursite.com/child' and root as '/child/'
url: http://lihui-snippets.cn/ #https://github.com/Hubery-Lee
root: /
permalink: :year/:month/:day/:title/
permalink_defaults: http://lihui-snippets.cn
```

## 文章加密访问

### 该加密方法密码暴露在网页调试代码中

1.配置加密功能，打开themes->next->layout->_partials->head.swig文件,在以下位置插入这样一段代码：
{%asset_img password.png 插入位置%}

``` bash 
<script>
    (function(){
        if('{{ page.password }}'){
            if (prompt('请输入文章密码') !== '{{ page.password }}'){
                alert('密码错误！');
                history.back();
            }
        }
    })();
</script>
```
在scaffolds文件夹post.md文件中，加入`password: `,新建博客将有如下的形式文件头；
``` bash
---
title: {{ title }}
date: {{ date }}
categories:
tags:
description:
password: 
---
```
2.设置给文章设置访问密码，经过以上的配置，`hexo new "newblog"`在`password: #密码`设置密码；也可以在以往的文章设置加密访问，只需在文章头中加入`password: #密码`即可；
``` bash
---
title: The use of gnome-screenshot command
date: 2018-09-11 16:12:50
tags: [linux tool]
categories: linux tool
description: gnome-screenshot command
password: pass
---
```
如，要访问这篇The use of gnome-screenshot command文章就需要输入密码pass;

### 该加密方法加密效果更好

以上方法给文章加密，可以通过浏览器调试界面看到网页密码，故而考虑另外的文章加密方式，可以参考留言版中的[hexo-blog-encrypt](https://github.com/MikeCoder/hexo-blog-encrypt/blob/master/ReadMe.md)地址尝试另一种加密方式；注意，对next主题，安装`hexo-blog-encrypt2.0.*`;对加密文章的头文件写法如下：
``` bash
---
title: The use of gnome-screenshot command
date: 2018-09-11 16:12:50
tags: [linux tool]
categories: linux tool
abstract: gnome-screenshot command;encrypt this article
password: pass
message: Please input password to read
---
```
其中，`abstract`后面写的是摘要，即是非加密文章头的`description`功能一样；`message`是加密文章所特有，指的是设置提示输入密码；`password`后面是设置的密码；
Bug在打开文章页面后，不再显示摘要，解决办法是再加一遍`description`,故而，完全正确的加密文章抬头应该这么写：
``` bash
---
title: The use of gnome-screenshot command
date: 2018-09-11 16:12:50
tags: [linux tool]
categories: linux tool
abstract: gnome-screenshot command;encrypt this article
password: pass
message: Please input password to read
description: gnome-screenshot command;encrypt this article
---
```
经过测试，直接用`description`替代`abstract`也能达到这样的效果,并不存在Bug；
``` bash
---
title: The use of gnome-screenshot command
date: 2018-09-11 16:12:50
tags: [linux tool]
categories: linux tool
description: gnome-screenshot command;encrypt this article
password: pass
message: Please input password to read
---
```
`Bug: 第二种加密方式，没法自动生成文章目录栏；`

## 访问量设置

采用busuanzi 和leancloud设置，在themes的文件夹下`_config.yml`中打开busuanzi配置，如下
``` bash
# Show PV/UV of the website/page with busuanzi.
# Get more information on http://ibruce.info/2015/04/04/busuanzi/
busuanzi_count:
  # count values only if the other configs are false
  enable: true
  # custom uv span for the whole site
  site_uv: true
  site_uv_header: <i class="fa fa-user"></i>
  site_uv_footer:
  # custom pv span for the whole site
  site_pv: true
  site_pv_header: <i class="fa fa-eye"></i>
  site_pv_footer:
  # custom pv span for one page only
  page_pv: false
  page_pv_header: <i class="fa fa-file-eye"></i>
  page_pv_footer:
```
其中，`site_uv`指的是user visitors,`site_pv`指的是passager visitors; `<i class="fa fa-file-eye"></i>`设置的是显示图标

对于文章的阅读量也可采用leancloud的应用来设置，如下：
``` bash
# Show number of visitors to each article.
# You can visit https://leancloud.cn get AppID and AppKey.
leancloud_visitors:
  enable: true
  app_id:  #<app_id>
  app_key:   #<app_key>
``` 
相对于busuanzi统计计数方法，leancloud方法能通过leancloud账户管理，并且leancloud统计的阅读量能够在首页显示；busuanzi统计数据无法在首页显示；leancloud应用的配置可以参考这篇文章 [参考文章链接](https://www.meiwen.com.cn/subject/yssswftx.html)

## 评论功能设置

评论功能采用leancloud valine应用，国内其他的友言、畅言和以及来必力都不能匿名评论，国外的gitalk,gitment以github用户授权评论，Hypercomments，Disqus等都被国内墙的厉害；只有国内leancloud应用具有匿名评论功能；在next主题下的`_config.yml`配置如下:
``` bash
# Valine.
# You can get your appid and appkey from https://leancloud.cn
# more info please open https://valine.js.org
valine:
  enable: true
  appid:  ooozwlclX00aJabPvk1WTj7J-gzGzoHsz # your leancloud application appid
  appkey:  CnXrRUVdUdMXgEvGbdolWGYX # your leancloud application appkey
  notify: false # mail notifier , https://github.com/xCss/Valine/wiki
  verify: false # Verification code
  placeholder: Just go go # comment box placeholder
  avatar: mm # gravatar style
  guest_info: nick,mail,link # custom comment header
  pageSize: 10 # pagination size
```

## 站外分享功能

具体的配置，可以参考文章开头列出的参考链接；在此，我只是用next主题模版，不作具体深入配置，工作中心放在作笔记上；在`_config.yml`中，打开百度分享选项即可：
``` bash
# Baidu Share
# Available value:
#    button | slide
# Warning: Baidu Share does not support https.
baidushare:
  type: slide
```

## 侧边栏社交小图标设置

next主题的网站小图标采用FrontAwesome插件[frontawesome icon site](https://fontawesome.com/icons?from=io);在实际应用中，在frontawesome网站搜索图标，在next主题的配置文件中用名字直接应用就行了，举例如下；
``` bash
# Social Links.
# Usage: `Key: permalink || icon`
# Key is the link label showing to end users.
# Value before `||` delimeter is the target permalink.
# Value after `||` delimeter is the name of FontAwesome icon. If icon (with or without delimeter) is not specified, globe icon will be loaded.
social:
  GitHub: https://github.com/Hubery-Lee || github
  Runoob: https://www.runoob.com || cube
  #Google: https://plus.google.com/yourname || google
  #Twitter: https://twitter.com/yourname || twitter
  #FB Page: https://www.facebook.com/yourname || facebook
  #VK Group: https://vk.com/yourname || vk
  #StackOverflow: https://stackoverflow.com/yourname || stack-overflow
  #YouTube: https://youtube.com/yourname || youtube
  #Instagram: https://instagram.com/yourname || instagram
  #Skype: skype:yourname?call|chat || skype

social_icons:
  enable: true
  icons_only: false
  transition: false
```
以上脚本中的`github,cube`即是在frontawesome上搜索到的图标名称；同样，links的图标也是这么配置的
``` bash
# Blog rolls
links_icon: globe
links_title: Index
#links_layout: block
links_layout: inline

links:
  Geant4: http://geant4.web.cern.ch/
  Root: https://root.cern.ch/
```
其中，`globe`即是frontawesome搜索到的图标名称；

## 设置网站图标

若要对网站图标进行修改，只需将你要改的图标拷贝到`themes/next/source/images/`文件夹下，并修改`themes/next/_config.yml`文件中的，favicon后面对应的图片文件名即可；
``` bash
# For example, you put your favicons into `hexo-site/source/images` directory.
# Then need to rename & redefine they on any other names, otherwise icons from Next will rewrite your custom icons in Hexo.
favicon:
  small: /images/favicon-16x16-next.png
  medium: /images/favicon-32x32-next.png
  apple_touch_icon: /images/apple-touch-icon-next.png
  safari_pinned_tab: /images/logo.svg
  #android_manifest: /images/manifest.json
  #ms_browserconfig: /images/browserconfig.xml
```

## 主题配色修改

修改`themes/next/source/css/_variables/base.styl`文件；具体配色，暂时没有调整；另外`next/_config.yml`中有5种可直接用的配色方案，如下：
``` bash
# Code Highlight theme
# Available value:
#    normal | night | night eighties | night blue | night bright
# https://github.com/chriskempson/tomorrow-theme
highlight_theme: night eighties
```

## 头部顶栏背景颜色或图片设置

1.在themes/next/source/css/_schemes/Mist/_header.styl中以下代码中修改颜色（我采用Next-Mist主题）
``` bash
.header { background: $blue-bright; }
```
2.也可改为背景图片，背景图片的添加如下：
``` bash
.header { background: url('../image/background.jpg'); }
```
将你要作为背景的图片`background.jpg`放到`Hexo/source/images/`文件夹下；当然你也可以采用图片网址链接，如：
``` bash
.header { background: url('http://xx.xx.xx.com/hexo/image/header-backgroud.jpg'); }
```

## 页脚设置

在next/_config.yml中，修改`footer:`下面的配置，如下：
``` bash
footer:   
  ##这一段为页脚设置，footer英文意思即为页脚意思
  # Specify the date when the site was setup.
  # If not defined, current year will be used.
  #since: 2015

  # Icon between year and copyright info.
  icon: user

  # If not defined, will be used `author` from Hexo main config.
  copyright:
  # -------------------------------------------------------------
  # Hexo link (Powered by Hexo).
  powered: false

  theme:
    # Theme & scheme info link (Theme - NexT.scheme).
    enable: false
    # Version info of NexT after scheme info (vX.X.X).
    version: false
  # -------------------------------------------------------------
  # Any custom text can be defined here.
  #custom_text: Hosted by <a target="_blank" href="https://pages.github.com">GitHub Pages</a>
```