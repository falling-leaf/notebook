# Chapter 1: js简介及语法
## 1.1 javascript的用法
- js代码必须位于`<script>`与`</script>`标签之间。

javascript代码的位置可在：
1. 文件内：`<body>`或`<head>`部分。
2. 文件外：通过`<script src="file.js"></script>`调用

## 1.2 javascript的输出
js有如下方式输出数据：
- window.alert():弹出警告框
- document.write():写入html文档
- innerHTML:写入html元素
- console.log():写入浏览器的控制台

举例四种方法的使用：
```js
<!DOCTYPE html>
<html>
<body>
<h1>页面</h1>
<p id = "demo">段落一</p>
<script>

window.alert(5 + 6); //弹出内容为"11"的警告

document.getElementById("demo").innerHTML = "update"; //更改demo的内容

document.write("a"); //重写整个html为"a"

console.log(5 + 6); //在控制台输出"11"
</script>
</body>
</html>
```

## 1.3 javascript的语法
javascript有如下字面量类型：
> 也可以理解为数据结构

1. 数字字面量：整数/小数/科学计数
`3.14 1001 123e5`
2. 字符串字面量：可用单引号/双引号
`'abc' "abc"`
3. 表达式字面量：用于计算
`5 + 6`
4. 数组字面量：定义一个数组
`[40, 100, 1, 5, 25, 10]`
5. 对象字面量：定义一个对象

```js
var person =
{
    first: "ab",
    last: "cd",
    id: 123,
    full: function()
    {return first + last;}
};

var fullname = person.full(); //值为"abcd"
var fullfunc = person.full; //值为"function(){return first + last}"
var firstname = person.first;
var firstcopy = person["first"]; //以上两种方法均可得到值"ab"
```

6. 函数字面量：定义一个函数
`function func(a, b){return a * b;}`

可以通过`typeof varname`来查询其字面量的类型（string/number/object/boolean）

*注：此时数组被视作object类型。*

js的变量定义名为*var*，可以用字面量为其赋值。

> 换言之，var可以是数/字符串/对象/数组

在var的使用中要注意如下情况：
1. 重复声明：
```js
var object = "one";
var object;
```
此时，`object`的值仍然是`"one"`，并且这样的语法是被允许的。

2. 直接声明：
```js
//之前无定义
var var1 = 1;
var2 = 2;
```
此时，`var2`是作为对象`window`的一个属性存在，你可以通过`window.var2`获取它的值。
它在全局范围内可使用。

*注 1：数+字符串，结果为字符串。例：1 + “2” = “12”。*

*注 2：javascript对大小写敏感。*

*注 3：javascript使用的关键字，包括关键字的用法与C++类似。*

*注 4：javascript可以使用‘\’对一行代码换行，但最好在数据内而不是指令结构内换行。*


