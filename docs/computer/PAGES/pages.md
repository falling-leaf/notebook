# 静态网页的设置

## step 0. 概述

### 0.1 目的

本部分主要描述该网页是如何搭建的。

### 0.2 使用工具

- python
- mkdocs
- mkdocs-material
- markdown

## step 1. 预安装

本项目需要你的电脑上安装有python下属的包mkdocs及其材料包，安装步骤如下：

1. 在[此网址](https://wiki.python.org/moin/BeginnersGuide/Download)下载python
2. 在命令行中输入 `pip install mkdocs`下载mkdocs
3. 在命令行中输入 `pip install mkdocs-material`下载对应包体

## step 2. mkdocs的工作架构

mkdocs是一种将markdown文件整理为docs文件的方法。

在本项目中，我们主要通过mkdocs配合github的方式，将markdown文件以静态网页的方式展现出来。

本部分只描述如何内部构建mkdocs，开始制作时请移步step 3。

### 2.1 mkdocs的文件格式

对整个文件夹，类似于如下结构：

- ./main //主文件夹
  - README.md //用于github上的README.md
  - mkdocs.yml //描述网页构建的整体结构
  - ./site //此文件夹会自动生成，内容为输出的html文件
  - ./docs //用于存放所有的文档
    - index.md //主页面的文档，必须存在
    - file1.md //其余文档结构随意，可以添加子文件夹
    - ./part1
      - file2.md

### 2.2 mkdocs.yml的写法

mkdocs.yml文件将告诉mkdocs要如何对docs文件夹内的文档进行处理。

```
# 第一部分：网页的名称、信息
site_name: yourname
site_url: https://yourname.github.io/yourfile/
site_author: yourname
site_description: yoursite

# 第二部分：网页的导航（所有名称均可替换）
# 这里将决定你最终展示出的文件的结构，冒号后面对应的链接应为以docs为根目录下的相对路径
nav:
- main:
  - home: index.md
  - introduction: introduction.md
- part1:
  - chapter1: ./part1/chapter1.md

# 第三部分：网页的设计（除却颜色以外建议不要修改）
theme:
  name: material

  palette:
    - media: "(prefers-color-scheme: dark)"
      scheme: slate
      primary: black
      accent: teal
      toggle:
        icon: material/brightness-4
        name: 切换至日间模式
    - media: "(prefers-color-scheme:light)"
      scheme: default
      primary: green
      accent: yellow
      toggle:
        icon: material/brightness-7
        name: 切换至夜间模式
  language: 'zh'

# 第四部分：markdown扩展语法（可以补充更多的扩展）
markdown_extensions:
  - admonition
  - codehilite:
      guess_lang: false
      linenums: false
  - toc:
      permalink: true
  - footnotes
  - meta
  - def_list
  - pymdownx.arithmatex
  - pymdownx.betterem:
      smart_enable: all
  - pymdownx.caret
  - pymdownx.critic
  - pymdownx.details
  - pymdownx.emoji:
      emoji_generator: !!python/name:pymdownx.emoji.to_png
  - pymdownx.inlinehilite
  - pymdownx.magiclink
  - pymdownx.mark
  - pymdownx.smartsymbols
  - pymdownx.superfences
  - pymdownx.tasklist
  - pymdownx.tilde
```


## step 3. 调试与运行

1. 在准备存储主文件夹的目录下打开命令行，输入 `mkdocs new filename`，filename为主文件夹的名称

> mkdocs会自动为你搭建好架构

2. 根据step 2的描述，构建你的页面
3. 在mkdocs.yml所在位置的命令行中执行 `mkdocs serve`，则可以在http://127.0.0.1.8000/filename中看到你所构建的网页

> 这个网页是实时更新的，意味着只要你在修改文件后保存，页面将会立即刷新，便于调试。

> 此时网页仍为本地网页，他人无法查看。

4. 将你的主文件夹作为仓库上传到github上
5. 在mkdocs.yml所在位置的命令行中执行 `mkdocs gh-deploy`，将由github为你生成一个https://yourname.github.io/filename的网址，此时网址内就是你设计的网页。

*注：此方法设计出的网页为静态网页，无法与他人交互，大多用于储存并展示信息*