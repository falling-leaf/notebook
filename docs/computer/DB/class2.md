# class 2/2024.3.7

## chapter 2: introduction to relation model

### 表的基本构成

#### 属性(attribute)

- 属性一般有一个域(domain)作为属性的取值范围。
- 属性一般要求具备原子性(atomic)。
- 对未知的值的属性，其值为空值(null)，只该值未知。

#### 键(key)

- 超键(superkey)是可以通过该键直接确定对应元组(tuple)的键。

> 例如：学号

**注：超键也可以是一系列键的集合，能够辨别所有元组即可。**

- 候选键(candidate key)是超键中最小的。

> 即，包含候选键的键的集合必然是超键。

*注：候选键不唯一。*

- 主键(primary key), 是从候选键中选出的一个。

**主键可以是多个。**

- 外键(foreign key), 一个表对另一个表键的引用。

**外键限定，设置外键的表中出现的值在被引用的表中必须出现。**

### 关系代数(relational algebra)

- 它是过程式语言(procedural language)
- 算子为select/project/union/set difference/catesian product/rename

#### 算子

- (select): $\sigma$

$\sigma _p(r)$意为在r中选取满足p的内容

**注：p中允许出现等/不等/大于/大等于/小于/小等于/与/或/非**

- 投影(project): $\Pai$

$\Pai _{a_1,a_2}(r)$意为在r中选取$a_1,a_2$的所有值

- 笛卡尔积(catesian product): $\times$

$p_1\times p_2$意为对每一个$p_1$结合每一个$p_2$生成行(其他元素也在表格中)。

换言之，最终表的行数应为$c_1\times c_2$

- 结合(join): $\theta$ (事实上不是这么写的)

$r\theta _p s = \sigma _{p} (r \times s)$

- 并(union): $\union$

若令R并S有效，则：

- r与s有相同的元数
- 属性的域必须是兼容的(compatible)

（事实上，R并S就是把这两个表合并起来）

- 交(set-intersection): $\and$
- 差(set difference): $-$

*交和差与正常的集合运算相同，在此不做赘述。*

- 赋值(assignment): <-

P <- expression即可用P代替expression

- 重命名(rename): $\rou$

$\rou _x (E)$: 将expression重命名为x（x可以为一个函数，如$x(a_1,a_2,...)$）

#### 等价查询

同样的查询目的，可以用不同的查询语句达到同样的目的。

但显然，运算的速度和难度是不一样的。

一般，我们尽可能将笛卡尔积作为最后一步来运算，避免太多冗余数据的生成。

## chapter 3: introduction to SQL

### 数据类型+域：

- char(n)
- varchar(n)
- int
- smallint
- numeric(p,d)
- real

### 语法：

- 此处语法可见lav conclusion总结。

```sql
select a
from b
where c
group by d
having e

```
