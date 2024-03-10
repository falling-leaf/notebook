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
```sql
create table table_name(
    attr1 int primary key, -- 令attr1为primary key
    attr2 char(40),
    attr3 varchar(40),
    primary key(attr2), -- 令attr2为primary key
)
```


### 视图相关：

### 索引相关：

### 查询语句相关：

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
