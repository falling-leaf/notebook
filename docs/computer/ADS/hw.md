## Chapter 11

单选2-2：

题目要我们求最大生成树与“选取每个点最大的边”的比较关系。

首先，第二种方法不会出现环，这与数据库中的拓扑检测锁是一个原理：每次都选最大的，那么最后一条边要大于第一条边（但事实上由于在这个节点率先选择的是第一条边，因此矛盾）

这意味着第二种方法至少构成了理论最大生成树的一部分（因为不确定是否联通）

那么显然$w(T) \geq w(S)$,选C


单选2-3：

最小生成树路径总cost记作C，则

$$C < A* < 2C$$

（这是因为通过走回头路的方式，以最小生成树的路径必然也能够走到所有点，题目要求代价为“每条边最多走一次回头路”，即2-approximation

那么显然，pre/post都可以（每次移动到的都是相邻的节点），而level显然不行

（看起来in应该也没问题，它路线应该和post一样