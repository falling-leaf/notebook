<div align='center'>
	<font size="70">实验2：SQL数据定义和操作</font>
</div>

## 前言
本报告较长（截图较多），可根据索引查找相应的实验部分。

## 实验目的：

1. 掌握关系数据库语言SQL的使用。
2. 使所有的SQL作业都能上机通过。

## 实验平台：

1. 数据库管理系统：SQL Server 2000或MySQL

## 实验内容和要求：

1. 建立数据库。
2. 数据定义：表的建立/删除/修改；索引的建立/删除；视图的建立/删除。
3. 数据更新：用insert/delete/update命令插入/删除/修改表数据。
4. 数据查询：单表查询、多表查询、嵌套子查询等。
5. 视图操作：通过视图的数据查询和数据修改。
6. 所有的SQL作业都能上机通过。

## 实验过程：

### 建立数据库：

打开MySQL Workbench，本地登录；

点击创建图标后如下图所示：
![1709282048890](image/report2/1709282048890.png)

我们命名之为“honkai3”，于是发现成功创建了：
![1709282154970](image/report2/1709282154970.png)

### 数据定义：表的建立/删除/修改；索引的建立/删除；视图的建立/删除：

点击SQL+，打开一个SQL文本：
![1709282238673](image/report2/1709282238673.png)

> 注：选中要执行的部分，点击“闪电”即可运行，要刷新才能看到数据库的当前状态。

#### 表的建立：

- 这个数据库中现在还没有表：
  ![1709282891421](image/report2/1709282891421.png)
- 运行如下代码：
  ![1709282933316](image/report2/1709282933316.png)
- 刷新后我们发现新建了一个表：
  ![1709282963513](image/report2/1709282963513.png)

#### 表的修改：

- 用下面这段命令添加一个“武器是否装备”的行：
  ![1709283062064](image/report2/1709283062064.png)
- 运行刷新后发现确实出现了：
  ![1709283113788](image/report2/1709283113788.png)

#### 表的删除：

- 我们先建好一个将要被删除的表：
  ![1709283219928](image/report2/1709283219928.png)

> 要把红圈内的东西删掉

- 利用 `DROP TABLE test`来删掉它：
  ![1709283280211](image/report2/1709283280211.png)

结果如下：

![1709283295837](image/report2/1709283295837.png)


#### 索引的建立：

- 现在这个表是没有索引的：
![1709283455530](image/report2/1709283455530.png)

- 我们用如下语句来建立一个索引：
![1709283528421](image/report2/1709283528421.png)

- 于是出现了索引：
![1709283555928](image/report2/1709283555928.png)

#### 索引的删除：

- 接上面步骤，执行下面的语句：
![1709345599703](image/report2/1709345599703.png)

- 发现索引确实删除了：
![1709345675145](image/report2/1709345675145.png)

#### 视图的建立：

- 用如下命令调整数据库中的数据，并建立视图：
![1709347348553](image/report2/1709347348553.png)

- 发现建立了视图：
![1709347389113](image/report2/1709347389113.png)

#### 视图的删除：

- 用如下命令进行视图的删除：
![1709347507438](image/report2/1709347507438.png)

- 发现视图确实删除了：
![1709347528438](image/report2/1709347528438.png)

### 数据更新：用insert/delete/update命令插入/删除/修改表数据。

#### 插入数据：

- 执行如下语句，插入一些数据：
![1709348181165](image/report2/1709348181165.png)

- 执行`select* from person`后如下图所示：
![1709348238776](image/report2/1709348238776.png)

#### 修改数据：

- 执行如下语句，将“爱莉希雅”的等级修改为100：

> 要注意在安全模式下，'where'后面跟的必须是key

![1709348444412](image/report2/1709348444412.png)

- 效果如下：
![1709348502089](image/report2/1709348502089.png)

#### 删除数据：

- 执行如下语句，将“爱莉希雅”删除：
![1709348674477](image/report2/1709348674477.png)

- 效果如下：
![1709348696716](image/report2/1709348696716.png)

### 数据查询：单表查询、多表查询、嵌套子查询等。
#### 单表查询：
- 查询名称为“彼岸双生”角色的属性和等级：
![1709360286936](image/report2/1709360286936.png)

- 结果如下：
![1709360309274](image/report2/1709360309274.png)

#### 多表查询：
更新表单数据，现在数据库内有两个表，其中的数据如下所示：
- 表1名为person，数据如下：
![1709360859119](image/report2/1709360859119.png)

- 表2名为other，数据如下：
![1709361805458](image/report2/1709361805458.png)

- 现在，将用多表查询的方式，将两个表“合并”起来：
![1709361850461](image/report2/1709361850461.png)

- 结果如下（提取到名字相同的角色的属性和实名）：
![1709361884500](image/report2/1709361884500.png)

#### 嵌套子查询：
我们可以利用`()as`来进行嵌套的限制，最终找到我们想要的数据。
这里，我们先将“彼岸双生”的等级设置为100；
![1709362429449](image/report2/1709362429449.png)

我们运行如下命令：
![1709362450496](image/report2/1709362450496.png)

它的意思是：
- 在person和other中，寻找name相同的元素组，提取它们的名称/属性/等级/实名，并将提取表定义为information
- 从information中，在name为“彼岸双生”的元素组中，选取level最大的值，作为level_max显示出来

最终效果如下：
![1709362634687](image/report2/1709362634687.png)

#### 视图数据查询：

- 利用如下代码，创建视图并查询其中姓名的数据：
![1709363245194](image/report2/1709363245194.png)

- 结果如下：
![1709363260309](image/report2/1709363260309.png)

#### 视图数据修改：

- 利用如下代码，将“彼岸双生”的等级乘2：
![1709389077563](image/report2/1709389077563.png)

- 效果如下：
![1709389092627](image/report2/1709389092627.png)

- 再看表中的数据，彼岸双生的等级也被更改为了200：
![1709389149637](image/report2/1709389149637.png)
