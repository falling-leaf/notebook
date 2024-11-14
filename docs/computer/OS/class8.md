## chapter 8: 主存

### 8.1 背景

主存发展的历程：

- 磁鼓存储器（drum memory）
- 延迟线存储器（delay line memory）
- 磁芯存储器（core memory）

Semiconductor(半导体)：

- DRAM：动态随机存取存储器（需要不断刷新才能更新，用于内存）
- SRAM：静态随机存取存储器（不需要刷新即可更新，用于cache）
- ROM：只读存储器（只读，用于存储不可写的数据（如操作系统））

Memory wall:

主存（Memory）要远比进程慢，并且也消耗更多的能量。这意味着主存限制了进程性能的发展。

NVM技术：

NVM：非挥发性存储器（非易失性存储器）

- Phase-Change Memory(PCM): 相位变化存储器（原理是通过相变材料在晶态和非晶态之间的切换进行数据的存储）
- ReRAM/RRAM: 电阻式存储器（通过施加电压或电流，让材料的电阻在高低之间切换，从而实现数据的存储）

更多的方法：内存计算（processing in memory），即在内存中完成计算，不再需要CPU的介入。（通过忆阻器（memristor）等实现）

### 8.2 交换（swapping）

### 8.3 连续内存分配（contiguous memory allocation）

### 8.4 分页（paging）

### 8.5 页表结构（structure of the page table）

### 8.6 分段（segmentation）

### 8.7 举例：Intel Pentium
