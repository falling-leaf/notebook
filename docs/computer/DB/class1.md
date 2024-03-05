# class 1/2024.2.29
## chapter 0: 课程要求

- 作业/练习：10%
- quiz：10%（5次）
- 实验：30%
- 期末：50%（可携带一张A4纸）

## chapter 1: introduction
### 数据库的定义
数据库（DBMS,database management system）
- 支持收集、管理数据
- 支持查询数据
- 环境方便且便捷

数据库的目的：解决如下问题：
- 数据冗余与不一致
- 存取数据困难
- 数据孤立，数据孤岛
- 完整性问题
- 原子性问题（即：某个数据/操作不可分，其结果只有成功/不成功两种）
- 并发访问异常
- 安全性问题

数据库的特征：
- 数据持久性
- 数据访问便利性
- 数据完整性
- 多用户并发控制
- 故障恢复
- 安全控制

### 数据模型
数据模型(data model)是描述如下事物的工具：
- 数据
- 联系
- 语义
- 约束

典型的模型如下：
- relational model:关系模型
- Entity-Relationship model:实体-联系模型（主要用作数据库设计）
- semi-structured data model(XML):半结构化数据模型
- object-based data models:基于对象的数据模型
- other older models...

### 抽象层次
1. 物理层(physical level)：数据具体如何存储
2. 逻辑层(logical level)：描述数据之间的关系
3. 视图层(view level)：根据用户的需求展示需要的内容，隐藏数据处理的细节等

相邻层次之间存在映射，构成整个体系。

**而因为这个特点，我们要求在对某个层次修改时，不会影响其他层次的运作。**

### 模式和实例
模式(schema)：数据库的总体设计
- 逻辑模式（即哪些数据构成一个表，等等）
- 物理模式

实例(instance)：数据库内的具体内容

### 数据库语言
- DDL(data definition language)：数据定义语言（用于定义模式）

eg：
```sql
create table instuctor(
    ID char(5),
    name varchar(20),
    salary numeric(8,2)
)
```

数据字典(data dictionary)：用于存储数据模板（就是上面那个东西）

数据模板，也可以称作元数据(metadata)，描述数据的关系、约束、权限等

- DML(data manipulation language)：数据操作语言（用于操作数据）

DML也可认为是查询语言(query language)

DML有两种类型：
1. 过程式DML(procedual DML)：告诉机器需要哪些数据/如何得到数据
2. 非过程式DML(declarative DML)：只需要告诉机器需要哪些数据

- SQL Query language

SQL往往为输入一系列table（也可为1个），返回一个简单的table（一个元素也可为table）

eg:
```sql
select name
from instructor
where dept_name = 'comp.sci.'
```

上面这段代码意为：从instructor这个table中，找到属性dept_name的值为comp.sci的组元，选取属性name的值。

SQL不是一个图灵机的等价语言。

因此，SQL往往嵌入在高级语言中，来完成各种复杂任务。

> SQL不支持用户的交互

- database access from application program

### 数据库设计
- 存储管理器
- 查询处理器
  - DDL解释器
  - DML编译器（包括查询方式的优化）
  - 查询执行引擎
- 事故管理器

作业：p32/1.7，1.8，1.9，1.15