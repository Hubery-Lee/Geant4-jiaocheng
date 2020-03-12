---
title: Add menubar and search function to hexo blog
date: 2018-09-09 14:04:25
categories: 编程工具学习与应用
tags: [hexo]
description: This paper descrbles the method to add menubar and search function to my blog with hexo and shows the different ways to cite website with markdown scripts in hexo blog.md. Attention! My hexo-theme bases on hexo-theme-next.
---

## Add Menubar

In the theme folder, we can find the following scripts in the _config.yml file.
``` bash
# ---------------------------------------------------------------
# Menu Settings
# ---------------------------------------------------------------

# When running the site in a subdirectory (e.g. domain.tld/blog), remove the leading slash from link value (/archives -> archives).
# Usage: `Key: /link/ || icon`
# Key is the name of menu item. If translate for this menu will find in languages - this translate will be loaded; if not - Key name will be used. Key is case-senstive.
# Value before `||` delimeter is the target link.
# Value after `||` delimeter is the name of FontAwesome icon. If icon (with or without delimeter) is not specified, question icon will be loaded.
menu:
  home: / || home
  about: /about/ || user
  tags: /tags/ || tags
  categories: /categories/ || th
  archives: /archives/ || archive
  #schedule: /schedule/ || calendar
  #sitemap: /sitemap.xml || sitemap
  #commonweal: /404/ || heartbeat

# Enable/Disable menu icons.
menu_icons:
  enable: true

```
The default menubars are home and archives. I want to add tags, categories and about to menubar. The problems appear when I only note off the options in the above scripts.

After investigation about this problem, I find the ansower in this site  http://www.360doc.com/content/18/0521/13/14715637_755685918.shtml `method one to cite website`

[this site](http://www.360doc.com/content/18/0521/13/14715637_755685918.shtml)  `method two to cite website`

Actually, we should add folder with commond `hexo new page  menubar_name`, then corresponding folders will appear in the source folder which is the site configure source folder. Then add configure information in the correspongding index.md.
Take tags for example.

``` bash
$ hexo new page tags
```

We will see follow information in index.md.

``` bash
---
title: tags
date: 2018-09-09 13:34:49
---
```
Then we add `type: "tags"` to the index.md
``` bash
---
title: tags
date: 2018-09-09 13:34:49
type: "tags"
---
```
Similar methods are used to add categories and about to menubar.

## Add local search function to menubar

1. install `hexo-generator-search`, hexo-theme-next search function depend on this package.

``` bash
$ npm install hexo-generator-search --save
```

2. active the local search configure in theme configure file `_config.yml`.

``` bash
# Local search
# Dependencies: https://github.com/flashlab/hexo-generator-search
local_search:
  enable: true #false modified by hubery lee @2018/9/9
  # if auto, trigger search by changing input
  # if manual, trigger search by pressing enter key or search button
  trigger: auto
  # show top n results per article, show all results by setting to -1
  top_n_per_article: 1
```

