# class 1/2024.4.23

## the problem is software

75% of hacks happen at the application.

92% of reported vulnerabilities are in apps, not networks.

64% of developers are not confident in their ability to write secure code.

抖音：a-b test：简单的对比评价，决定上a还是b

设计层面/实现层面/操作层面的问题

安全问题不能只取决于单点的失败，单点的失败不代表全部工程的失败。

结对编程：一个人打，一个人看，两个人看同一台电脑

100：中间状态

200：正常

300：重定向

400：客户端错误

500：服务器错误

# class 3/2024.5.7

js是动态的，弱类型的语言

js是一个解释性的语言

在打代码的时候需要注意尽量不要copy/paste，而是将重复代码封装为函数

在共同开发前端时，要特别注意解耦等代码与设计规范

# class 4/2024.5.10

looking at the contributed data is looking into the past

(OWASP的创造理念，不止着眼于过去的数据)

数据库有CWE（对软硬件的漏洞的枚举类型）和NVD

# class 5/2024.5.14

白名单相比于黑名单更严格，因此默认不可，通过开放权限来进行处理

injection相应的攻击方式

# class 6/2024.5.17

防火墙利用--来进行对注入攻击的判断

一般来说，跨站脚本本身是不被浏览器允许的，这是一个默认的安全准则

myspace的跨站脚本：设置蠕虫，攻击结果是加好友(Samy's profile)

几乎所有的网站都不提供直接编写html的方法

# class 7/2024.5.21

strcpy一般在工程中是不允许使用的，很容易造成缓冲区溢出。可采用宏定义/定义为null的方式在头文件令其被判断为语法错误

宏定义实质上是一个字符串处理语句，在宏定义上括号加的尽可能多，避免二义性

编译时事实上并不关心函数具体的位置，在连接的时候才会去寻找函数对应的定义在哪里

# class 8/2024.5.24

char* buf存的是一个指针（在堆上）

char buf[100]存的是100个字节的空间（在栈上）

通过jump/call trick, 我们可以将shellcode存在memory中

# class 9/2024.5.28

如无必要，格式化字符串一定要写成常量，避免攻击者进行攻击

有一种复现机构QA，找到bug出现的具体场景

access/open Race: 通过首先判断access是否足够，再去进行fopen

fopen用effective id判断，access用实际id进行判断

从time to check 到 time to use之间，攻击者可以在这个空隙进行攻击

# class 10/2024.5.31

在switch/case中，如果不希望写break从而使代码简洁时，要写注释：Falls through以证明不是忘写了

不要改变const的值

不要在判断性语句（if）中用赋值语句

在判断表达式中，if(A && B && C),尽量不要让B正确的前提之一为A（例如A是存在这个东西，B是验证这个东西的值）

任何浮点数不能精确比较

# class 11/2024.6.4

3D渲染时忽明忽暗，原因就是浮点数的不精确导致的。

游戏服装中直接在商城买与从宝箱中开出来，涉及到的法案（会计准则）：永久道具会随着游戏生命周期而贬值，但有效期的道具是一次性付清的

游戏中抽奖概率必须公示，这也是法案之一

use-case在信息安全方面，不仅有用户的use，还有攻击者的use

# class 12/2024.6.7

fail safe: 当程序返回错误时，其值应当是安全的（红绿灯网络错误返回绿灯）