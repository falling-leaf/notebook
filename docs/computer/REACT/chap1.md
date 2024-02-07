# Chapter 1: React开发环境安装
> 本人在安装时出现了数个问题（似乎把所有坑都踩了TAT），因此先给出整个安装的流程

## step 1: 安装node.js
[node.js下载链接](https://nodejs.org/en)
点击上述链接，下载*多数用户使用*的node.js版本，勾选ADD-TO-PATH
在cmd上执行`npm -v`;`node -v`，如果返回版本号则安装成功

## step 2: 安装cnpm

**由于npm的证书用国内网访问网速过慢，因此需要用淘宝提供的镜像来继续安装。**

> 否则会持续提示tar的版本落后，并且重新安装tar不可解决此问题

在cmd上执行如下代码：

**注意！https://registry.npm.taobao.org/cnpm这个网址在2024.1.22正式到期，如若使用会报错证书过期！**

```
npm cache clean --force

npm config set registry https://registry.npmmirror.com

npm config get registry

npm install -g cnpm
```

## step 3: 安装create-react-app

执行如下代码以安装create-react-app:

`cnpm install -g create-react-app`

## step 4: 建立一个react应用

在你准备保存该应用的文件夹位置下用命令行执行：(appname可更改)

`create-react-app appname`

等待后提示*happy hacking!*则说明建立成功。

此时在*appname*文件夹目录下执行`cnpm start`，即可在本地网页上看到react为我们提供的默认页面。