## ahaslides question

### quiz 1

1. Which of the following is an example of a multi-user operating system?
- Android
- Windows 10
- **_Linux Ubuntu_**
- macOS

> Linux Ubuntu 是支持多用户的操作系统。

2. What is the main purpose of an operating system?
- Design graphics for games
- Control social media apps
- Play music and videos
- **_Manage computer hardware resources_**

> OS主要目的为管理计算机的硬件资源。

3. Which operating system was developed by Bell Labs in the late 1960s?
- Mac OS
- Windows 95
- **_UNIX_**
- MS-DOS

> 贝尔实验室在60年代末发明了UNIX操作系统；Mac OS最早版本在1984年；Windows 95是MS-DOS的后续版本，于1995年开发；MS-DOS是微软公司在1981年收购，并且在Windows 95出现之前一直作为Windows系列的操作系统。

4. Which of the following is not a function of an operating system?
- File management
- **_Compiler design_**
- Hardware control
- Memory management

> 显然，编译器设计是更高级别的设计任务，与OS无直接关系。

5. Which component of a computer system provides basic computing resources suach as the CPU, memory, and I/O devices?
- Users
- **_Hardware_**
- System & application programs
- Operating system

> 注意，提供计算资源的是硬件，而利用、分配硬件资源的是OS。

6. Which technology allows for the efficient use of physical hardware resouurces by dividing them into multiple virtual environments?
- Cloud Computing
- Hadoop eco-system
- Containers
- **_Virtualization_**

> 将硬件资源分配给多个不同的虚拟环境中，就是虚拟化技术。

7. Which of the following is true about the bootstrap loader in OS concepts?
- It is executed after the operating system is loaded.
- **_It loads the operating system into memory._**
- **_It is stored in ROM._**
- It is stored in RAM.

> bootstrap在是开机后第一个（且始终）运行的程序，它把OS的相关指令载入内存。由于它是被烧录进入计算机的，所以它被存储于只读内存（Read Only Memory）。

### quiz 2

1. What is the central component in the von Neumann architecture?
- Hard Drive
- GPU
- **_Memory_**
- Processor

> 注意！无论是进程管理器还是硬件设备，都是通过内存进行数据的传输、交互与处理的，因此内存是冯诺依曼架构的中心部件。

2. Which statement about I/O devices and CPU concurrency if false?
- CPU can move data between main memory and local buffers.
- **_I/O data is transferred directly to the main memory._**
- Device controllers inform the CPU via interrupts.
- Each device controller has a local buffer.

> I/O的数据需要通过先存到I/O device controller中的local buffer来进行与主存的数据交互。需要注意的是，DMA技术是针对device ocntroller和main memory，并且它的解释是（无CPU参与）。

3. Which component is responsible for informing the CPU that an I/O operation has been completed?
- local buffer
- I/O device
- **_device controller_**
- main memory

> device controller的作用为对外设与主存间的数据传输进行管理。在I/O数据传输结束后，device controller会向CPU发出“读取完毕”的信息。

4. What is the purpose of the interrupt vector?
- To save interrupted instruction addresses
- To generate traps
- To disable incoming interrupts
- To contain the addresses of all service routines

> 

