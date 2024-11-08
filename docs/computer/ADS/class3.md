# class 3/2024.3.12
## chapter 3: inverted file index
### 概述：
在搜索关键词时，如何进行索引的列表？

1. 方法1：把所有含有关键词的网页都找出来（x

过多的网页可被选中，不合理。

2. 方法2：将每个网页中所有的单词列出来，然后建立关联矩阵，再去找文本（x

矩阵过于稀疏，空间浪费太大。

3. 方法3：inverted file index

### 结构：
与方法2相似，但每一个词以“次数，（网页位置；所在文本位置）”存储

例如：假设对fire有"1; (2;7)"

那么就是，fire在所有网页中出现了1次，位置是在第2个网页的第7个词。

**思考：为什么要记录频率？**

当我们输入多个关键词时，我们可以从频率较小的词汇进行查询。

### 代码实现：
总体而言，这个程序并不难，只需注意以下几点即可：
- 对于word stemming(如process, processing)，这些词应当被化作同一类（但会失去某些精准的含义）
- 对于某些stop words/noisy words(如a, the, in等)，这些词单独列index是无意义的，因此应当被排除。
- 而对于stop words和real words的差别（如it和IT），也需要注意处理。
- dictionary的结构选取：可用B+tree（速度慢），也可用hashing（空间大）

### 优化：
- 压缩（compression）：

例如我们有如下的出现位置：

computer: 2,15,47,...

通过压缩，我们可以求这些数之间的间隔：2,13,32,...