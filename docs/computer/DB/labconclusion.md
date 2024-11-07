# 数据库实验总结

## lab 1-4

这4个lab比较简单，本人春一周报告基本就打完了（乐

主要还是对sql语句的熟悉和掌握：

这里将4个lab涉及到的sql语句列在下面，以便速查：

### 数据库相关：

#### 建立数据库：

```sql
create database base_name;
```

#### 使用数据库：

```sql
use base_name; -- 也可在引用表时用base_name.table来替换
```

### 表相关：

#### 建表：

- 设置主键：

```sql
create table table_name(
    attr1 int primary key, -- 令attr1为primary key
    attr2 char(40),
    attr3 varchar(40),
    primary key(attr2), -- 令attr2为primary key
)
```

- 设置外键：

```sql
create table table_name(
    attr1 varchar(8) primary key,
    attr2 varchar(50),
    foreign key(attr2) references another_table
)
```

- 设置not null（即插入时，这个值不能为空）：

```sql
create table table_name(
    attr1 varchar(8) primary key, -- 注：primary key默认not null
    attr2 varchar(50) not null 
)
```

#### 更新：

- 插入：

```sql
-- 无论如何，insert语句必须值与属性一一对应，没有的也要用null补
insert into table_name values(value1, value2, value3);
-- 等价于下面的语句：
insert into table_name(attr1, attr2, attr3) values(value1, value2, value3);
-- 后面的值同样不一定要用values定义：
insert into table_name
    select attr1, attr2, attr3
    from table_name;
```

- 删除：

```sql
delete from table_name;-- 删除表内的所有内容
-- 可以加where限定

drop table table_name; -- 删除表本身
```

- 调整：

```sql
alter table table_name add attr domain -- 增加attr属性
-- 注：对于新增的属性，已插入的元组的该属性为NULL

alter table table_name drop attr -- 删除attr属性
```

- 更新：
```sql
update instructor set salary = salary * 1.05;
-- 对表内的所有值进行更新操作。
-- 同样可用where限定
```

#### 查询：

查询语句比较广泛，基础结构如下：

```sql
select attr1, attr2
from table_name1, table_name2
where constaint
```

对于其他关键词，使用说明如下：

- distinct/all:

```sql
select distinct attr -- 相同值的attr只取一次
from table_name

select all attr -- 默认为select all
from table_name 
```

- \*/特殊的查询结构:

```sql
select * -- 选取所有的属性
from table_name

select '437' -- 返回一个值为437，但属性名未定义的表

select '437' as FOO -- 返回一个属性名为FOO，值为437的表（但基本不可用）

select 'A' -- 返回一个以table_name行数为行数的，列数为1，内容全为'A'的表
from table_name
```

- 运算符：（sql支持在语句内进行运算）

```sql
select salary/12 -- 返回的表格中salary值会被除12
from instructor -- 但实际的值不会改变
```

- where中可用的逻辑运算符

```sql
select attr1
from table_name
where attr2 = 'a' and attr3 <> 'b' or attr4 >= 'c'
-- and/or/not 可以被使用
-- </<=/>/>=/=/<>(不等于) 可以被使用
-- 也可以使用如下语句：
select attr1
from table_name 
where attr2 between 100 and 1000;
-- 意为 attr2 >= 100 and attr2 <= 1000
```

- as(重命名)：

```sql
select T.attr1
from table_name as T -- 在重命名语句之前/后都可以用
where T.attr2 > 1 -- as的生命周期仅在一个完整语句内

select T.attr2
from table_name T -- as可以省略

```

**自连接问题：**
可以将同一张表命名为两个，这样可以间接寻找二次关系：
```sql
select s2.supervisor
from selfconnect as s1, selfconnect as s2
where s1.person = "Bob" and s2.person = s1.supervisor; -- 寻找Bob的supervisor的supervisor
```

注：多重关系可能需要用递归，现在暂且按下不表。

- 正则表达式（字符串操作符）
```sql
select name
from instructor
where name like '%dar%'; -- %表示位置内可有任意字符（没有也行）

select name
from instructor
where name like '%d%r%'; -- 这样也可以的

select name
from instructor
where name like '_dar_'; -- _表示位置内有且仅有一个字符

-- 如果需要匹配'%'这个字符，可以使用转义（默认为'\'）

```

- 格式设置（order by）
```sql
select name
from instructor
order by name (desc/asc) -- 按照name降序/升序排列（默认升序）

也可以这样：
order by name, ID;
```

- 集合运算：可以对提取出的表们进行集合运算：
```sql
(select * from table_name where attr1 = 1)
union
(select * from table_name where attr2 = 1)
-- A并B
-- 可以将union换为intersect/except，分别为
-- A交B，A差B
-- 这些操作默认是distinct的，如果想要保留重复数据，使用：
union all -- 其他二者类似
```

- 空位判断（null）
```sql
select name 
from instructor 
where salary is null -- salary值为空
is not null -- 这个也可以用
-- 注：对null的所有算数运算结果全为null
-- 对比较运算符：null参与的任意运算结果为unknown
-- 对逻辑运算符：
-- and：一方为false时必为false，之后一方为unknown时必为unknown
-- or：一方为true时必为true，之后一方为unknown时必为unknown
-- 如果where后结果为unknown，则返回值为false
```

- select内的函数使用
```sql
select avg(salary) -- 选取salary的平均值
from instructor;
-- 相似可用的还有：
select count(salary) -- 选取salary的个数
select min(salary) -- 选取salary的最小值
select max(salary) -- 选取salary的最大值
select sum(salary) -- 选取salary的和

-- 可以通过group by限定选取的范围：
select avg(salary)
from instructor
group by dept_name; -- 返回值为以dept_name种类行数的avg
-- 如果select再加上dept_name，直接返回对应每个dept的avg

-- 同时，在group by后再对group进行选取，可用having来做：
select dept_name, avg(salary)
from instructor
group by dept_name
having avg(salary) > 42000 -- group by后每个值以组为单位
```

- 嵌套查询/对集合运算的扩展
```sql
-- in/not in:
select id
from section
where year = 2017 and 
    id in (select id
            from section
            where year = 2018);
-- 元素属于集合
-- not in同理，元素不属于集合
-- some/all:
select name
from instructor
where salary > some(select salary
                    from instructor
                    where year = 2018);
-- some: 集合中有一个元素满足，即返回true
-- 这意味着 a = some(A)与 a <> some(A)可能结果一样
-- all: 集合中每一个元素满足，即返回true
-- exists/not exists:
select id
from section as S
where year = 2017 and
    exists(select*
            from section as T
            where year = 2018
            and S.id = T.id);
-- exists为单目对集合的运算符，如果集合不为空则返回true
-- not exists同理
-- unique同样为单目对集合运算符，如果集合无重复值则返回true
```

- 预定义：with
```sql
with max_budget(value) as(--这是一个表，所以需要定义一个表作为承接
    select max(budget)
    from department
)
select department.name
from department, max_budget
where department.budget = max_budget.value;
--给函数预先定义的空间
```

- join类语句（用于from条目中）
```sql
select *
from table_a natural join table_b; -- 将a和b自然结合（所有相同的属性合并在一起）

select *
from table_a join table_b using (attr1) -- 针对attr1，将a和b结合在一起

select *
from table_a join table_b on (a_attr = b_attr) -- 更细致化合并的方式，利用on这个语句

select *
from table_a natural left outer join table_b;
-- 对table_a和table_b不同的部分，只保留table_a的多余项（换言之，它的输出比natural join多了a的部分（对应b不存在的部分为null））

select *
from table_a natural right outer join table_b;
-- 同理，但只保留b多余的部分

select *
from table_a natural full outer join table_b;
-- 对a和b多余的部分全部保留

select *
from table_a natural inner join table_b on (a_attr = b_attr);
-- 取a和b的交集

```



### 视图相关：

#### 建立：
用如下语句建立一个视图：
```sql
create view v as select * from table_a;
```

同时，可以通过别的视图来建立视图：
```sql
create view v1 as select * from table_a;

create view v2 as 
    select *
    from v1;
```

#### 更新：
```sql
insert into v values(value1, value2); -- 这时，插入操作会转化为对视图对应的表格的插入操作。
-- 但是，这有极大的限定条件，因为v是通过选择来获取的，对应的表不一定为1个，表中数据不一定对应等等
```

### 索引相关：

#### 建立：
```sql
create index i on table_name(attr1); -- 针对table中的attr1创建一个索引
```

### 完整性限制：
- not null(前文提过，限定该变量不可为空)
- primary key(前文提过，限定该变量为主键)
- foreign key(前文提过，限定该变量引用自其他表)
- unique(前文提过，限定某一列/某几列值是唯一的（但可为空）)
- check语句（具体的限定范围等）
```sql
create table a(
    id varchar(8),
    sec_id varchar(8),
    semester varchar(6),
    check (semester in ('Fall', 'Winter')) -- 限定插入的范围
)
```

- cascade语句（一般只用在外键/触发器中）

```sql
create table a(
    id varchar(8),
    foreign key(id) references b(o_id) on delete cascade;
    -- 这指的是当b中o_id被删除一条时，所有a中关于这一条的内容也被删除
    -- 同理亦有on update cascade
)
```

### 断言(assertion)
```sql
create assertion assertion_name check (...);
-- 全局生效
```

### 权限相关：

```sql
-- 注：可通过base_name.table_name.attr1避免二义性
-- 注：主键默认不可为空（not null）
-- 注：primary key/foreign key可以为多个
create table table_name(
    attr1 int, -- 设置attr1
    attr2 char(40), -- 设置attr2
    attr3 varchar(40), -- 设置attr3
    primary key(attr1), -- 令attr1为primary key
    check(attr1 > 0 and attr1 < 100), -- 限制attr1在0和100之间
    check(attr2 in("value1", "value2", "value3")) -- 限制attr2在value1,value2,value3之间
);

create table subtable(
    attr1 int,
    attr4 char(40)not null, -- 要求attr4不能为空
    attr5 varchar(40) primary key, -- 设置attr5为primary key
    foreign key(attr1) references table_name(attr1) -- 令table_name的attr1作为foreign key
)


alter table table_name add attr4 float; -- 在table_name表中增加类型为float的attr4作为属性

alter table table_name drop attr4; -- 删除table_name表中的attr4属性

drop table table_name; -- 删除表table_name

create index attr1_index on table_name(attr1); -- 在table_name中，对attr1创建索引

drop index attr1_index on table_name; -- 删除索引attr1_index

create view table_name_view -- 创建视图table_name_view
as 
select * -- 选取内容自行定义（*代表全部选取）
from table_name -- 从table_name中创建
where * -- 限制内容自行定义

drop view table_name_view -- 删除视图table_name_view


insert into table_name values(value1, value2, value3); -- 在表table_name中插入数据

update table_name -- 更新表table_name中的数据
set attr2 = value4 -- 对满足限制的元组，设置attr2为value4
where * -- 限制内容自行定义

delete from table_name -- 删除表table_name中的数据
where * -- 限制内容自行定义

select * -- 选取内容自行定义（*代表全部选取）
from table_name -- 从table_name中选取
where * -- 限制内容自行定义
-- 注：select/from/where后面的值都可以为多个或者是语句块，中间可以进行算数运算
-- 注：视图的查询/修改与表查询/修改相同

select distinct attr1
from table_name;

select all attr1
from table_name;
-- 以上两句中，前一句attr1不可出现重复的值，而后一句是可以的。
-- 默认是all

select '437' as FOO; -- 返回值就是一个一行一列，行值为“437”的，属性名字为FOO的表（无from/where）

select 'A'
from table_name; -- 返回值是多行一列，行数取决于table_name的行数，值全为'A'

select *
from table_name, subtable; -- 返回值是这两个表的笛卡尔积

select attr
from table
where attr like '%abc_'; -- 类似正则表达式，选取含有abc的attr（%表示任意字符串，_表示任意字符）

-- order by语句补充


delimiter // -- 设置//作为语句块的分割符，允许trigger语句中出现分号
create trigger value_present
    after update on table_name
    for each row
begin
    update subtable set attr4 = "value4" -- 令符合条件的attr4为value4
    where * -- 可自行加限定语句
end; // -- 结束trigger
delimiter ; -- 设置分号作为语句块的分隔符


create user 'user1'@'localhost' identified by 'password'; -- 新建用户/地址/密码

grant create on base_name.* to 'user1'@'localhost'; -- 赋予user1在base_name中create的权限

revoke create on base_name.* from 'user1'@'localhost'; -- 收回user1在base_name中create的权限

show grants for 'user1'@'localhost'; -- 查看user1的权限

```
