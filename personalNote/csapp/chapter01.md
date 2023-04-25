计算机系统由硬件和系统软件组成，共同工作来运行应用程序。

```c
#include<stdio.h>
int main(){
    printf("hello world! C");
    return 0;
}
```

追踪程序hello.c的生命周期—>创建，运行，输出，终止。

# 1 信息=位+上下文

hello.c即为**源程序**，hello程序的开始，程序员编写的文本文件—由字节（8个位组成一组）组成。

大部分使用**ASCII标准**。程序以字节序列的方式存储在文件中，每字节的整数值对应一个字符。只由ASCII字符构成的文件称为**文本文件**，其他文件称为**二进制文件**。

基本思想：系统中的所有信息都是由一串比特（位）来表示的。通过数据的上下文来区分不同的数据对象。数字的机器表示与实际数不同，为真值的有限近似值。

# 2 程序被其他程序翻译成不同格式

高级C语言—转化—>低级机器语言指令—打包—>可执行目标程序

```bash
gcc -o hello hello.c
./hello
```

![编译系统](https://dreaife-1306766477.cos.ap-nanjing.myqcloud.com/%E5%B1%8F%E5%B9%95%E6%88%AA%E5%9B%BE%202023-01-15%20165458.png)

编译系统

编译系统：预处理器、编译器、汇编器、链接器

- 预处理
  
    预处理器(cpp)根据#开头命令修改原始程序，将头文件内容直接插入到程序文本。
    
    hello.c—cpp—>hello.i
    
- 编译
  
    编译器(ccl)将上步.i文件翻译成.s文件，包含一个汇编语言程序。
    
    hello.i—ccl—>hello.s
    
- 汇编
  
    汇编器(as)将.s文件翻译成机器语言指令，并打包成可重定位目标程序，保存在.o的二进制文件中。
    
    hello.s—as—>hello.o
    
- 链接
  
    链接器(ld)合并当前.o文件以及调用库函数的预编译目标文件，得到可执行目标文件，可以被系统执行。
    
    hello.o+printf.o—ld—>hello
    

# 3 了解编译系统的帮助

1. 优化查询性能
2. 理解链接出现的错误
3. 避免安全漏洞

# 4 处理器读取解释指令

## 4.1 系统硬件组成

![系统的硬件组成](https://dreaife-1306766477.cos.ap-nanjing.myqcloud.com/%E5%B1%8F%E5%B9%95%E6%88%AA%E5%9B%BE%202023-01-15%20171549.png)

系统的硬件组成

1. 总线
   
    是贯穿系统的一组电子管道，携带信息字节进行传递。传送定长的字节块word（字）。字中的字节数随系统不同，为基本系统参数，如：4字节（32位），8字节（64位）。
    
    系统总线、内存总线、I/O总线
    
2. I/O设备
   
    负责系统与外部联系。输入的键盘和鼠标、输出的显示器、长期存储的磁盘等等。
    
    I/O设备通过控制器或者适配器与I/O总线相连。
    
    - 控制器和适配器区别
      
        封装方式不同。
        
        控制器：I/O设备本身或系统主板上的芯片组。
        
        适配器：一块插在主板插槽上的卡。
    
3. 主存
   
    是临时存储设备，存放程序和程序处理的数据。
    
    物理上是动态随机存取处理器（DRAM）芯片组成；逻辑上是一个线性的字节数组，各个字节地址唯一，地址从零开始。
    
4. 处理器
   
    中央处理单元（CPU），是解释存储在主存中指令的引擎。
    
    核心是一个大小为一个字的存储设备，叫程序计数器（PC），指向主存中的某条机器语言指令（的地址）。从通电开始，处理器不断执行PC指向的指令，再更新PC并执行下一条指令。
    
    处理器按照指令操作模型（由指令集架构决定）来操作，在模型中，指令按照严格顺序进行执行，执行一条指令包括：cpu从pc指向内存读取指令，解释指令中的位，执行指令指示的**简单操作**，更新pc以指向下条指令。
    
    如上简单操作并不多，它们围绕**主存**、**寄存器文件**[一个小的存储设备，由一些单个字长的寄存器组成，各自名字唯一]、**算术/逻辑单元**（ALU）[计算新的数据和地址值]进行。
    
    - 简单操作
        - 加载
          
            从主存复制一个字节或者字到寄存器，覆盖寄存器原来内容
            
        - 存储
          
            从寄存器复制一个字节或者一个字到主存的某个位置，以覆盖这个位置上原来的内容。
            
        - 操作
          
            把两个寄存器的内容复制到ALU,ALU对这两个字做算术运算，并将结果存放到一个寄存器中，以覆盖该寄存器中原来的内容。
            
        - 跳转
          
            从指令本身中抽取一个字，并将这个字复制到程序计数器(PC)中，以覆盖pc中原来的值
            
    
    处理器形式上是指令集架构的简单实现，实际上使用了非常复杂的机制来加速程序的执行。因此将处理器的指令集架构和处理器的微体系结构区分开来：**指令集架构**描述的是每条机器代码指令的效果；而**微体系结构**描述的是处理器实际上是如何实现的。
    

## 4.2 运行程序

过程：

shell程序执行指令，等待输入命令；输入`./hello`，shell程序将字符逐一读入寄存器，再存入内存；敲回车，执行命令；加载hello文件，将其中代码和数据从磁盘复制到主存。

![读取hello命令](https://dreaife-1306766477.cos.ap-nanjing.myqcloud.com/%E5%B1%8F%E5%B9%95%E6%88%AA%E5%9B%BE%202023-01-15%20205941.png)

读取hello命令

使用直接存储器存取（**DMA**），数据可以不通过处理器直接从磁盘到主存。

![磁盘加载可执行文件到主存](https://dreaife-1306766477.cos.ap-nanjing.myqcloud.com/%E5%B1%8F%E5%B9%95%E6%88%AA%E5%9B%BE%202023-01-15%20210054.png)

磁盘加载可执行文件到主存

然后开始执行hello程序的main中的机器语言指令，将“hello world! C”字符串中的字节从主存复制到寄存器，再从寄存器复制到显示设备，最终显示在屏幕。

![字符串输出到屏幕](https://dreaife-1306766477.cos.ap-nanjing.myqcloud.com/%E5%B1%8F%E5%B9%95%E6%88%AA%E5%9B%BE%202023-01-15%20210406.png)

字符串输出到屏幕

# 5 高速缓存重要

如上可以发现，系统花费了大量时间用于信息的移动，这些复制在一定程度上减慢了程序的工作。

针对处理器和主存速度上的差异，使用**高速缓存存储器**（cache），存放近期可能使用的信息。L1缓存、L2缓存…使用**静态随机访问存储器**（SRAM）硬件技术实现。利用高速缓存的**局部性**原理：程序具有访问剧本区域里的数据和代码的趋势。

利用高速缓存可以使程序的性能提高一个数量级。

![高速缓存存储器 cache](https://dreaife-1306766477.cos.ap-nanjing.myqcloud.com/%E5%B1%8F%E5%B9%95%E6%88%AA%E5%9B%BE%202023-01-15%20211426.png)

高速缓存存储器 cache

# 6 存储设备的层次结构

存储器层次结构，在处理器和一个较大较慢的设备间插入更小更快的存储设备。

主要思想是使用上一层的存储器作为低一层存储器的高速缓存。

![存储器层次结构](https://dreaife-1306766477.cos.ap-nanjing.myqcloud.com/%E5%B1%8F%E5%B9%95%E6%88%AA%E5%9B%BE%202023-01-15%20211607.png)

存储器层次结构

# 7 操作系统管理硬件

程序通过操作系统提供的服务来访问硬件。所有应用程序对硬件的操作都必须通过操作系统。

![计算机系统分层视图](https://dreaife-1306766477.cos.ap-nanjing.myqcloud.com/%E5%B1%8F%E5%B9%95%E6%88%AA%E5%9B%BE%202023-01-15%20212054.png)

计算机系统分层视图

操作系统可以防止硬件被失控的应用程序滥用和向应用程序提供简单一致的机制来控制复杂不同的硬件设备。其实现是由几个抽象概念（**进程**、**虚拟内存**、**文件**）来实现。

文件是对I/O设备的抽象，虚拟内存是对主存和I/O设备的抽象，进程是对处理器、主存和I/O设备的抽象。

![操作系统提供的抽象表示](https://dreaife-1306766477.cos.ap-nanjing.myqcloud.com/%E5%B1%8F%E5%B9%95%E6%88%AA%E5%9B%BE%202023-01-15%20212428.png)

操作系统提供的抽象表示

## 7.1 进程

程序运行时，操作系统会提供当前程序正在独占处理器、主存和I/O设备的假象。该假象是通过进程来实现的。

**进程**是操作系统对正在运行的程序的抽象。一个系统可以有多个进程同时运行，而每个进程好像各自独占着使用硬件。

**并发**运行是指一个进程指令和另一个进程指令交错执行。其通过处理器在进程间切换来实现，实现的机制被称为**上下文切换**。

**上下文**是操作系统跟踪的进程运行所需的所有状态信息的这种状态，包括PC、寄存器的当前值、主存内容等等。由于单处理器系统只能执行一个进程的代码，当需要运行其他进程时，就需要**上下文切换**（保存当前进程的上下文，恢复新进程的上下文）。

![进程的上下文切换](https://dreaife-1306766477.cos.ap-nanjing.myqcloud.com/%E5%B1%8F%E5%B9%95%E6%88%AA%E5%9B%BE%202023-01-15%20213547.png)

进程的上下文切换

如图，进程的切换是由操作系统**内核**（kernel）管理的，即操作系统代码常驻主存的部分，是操作系统管理全部进程所用代码和数据结构的**集合**。当应用程序需要操作系统功能时，内核就会执行一条特殊的**系统调用**（system call）指令，将控制权传递给内核。然后内核执行请求的操作，再返回给应用程序。

## 7.2 线程

一个进程可以由多个执行单元（**线程**）组成，每个线程运行在进程的上下文中，共享同样的代码和全局数据。多线程相较多进程更容易共享数据，因此线程一般比进程高效。

## 7.3 虚拟内存

**虚拟内存**为进程提供了其独占地使用主存的假象。每个进程看到的内存一致，称为**虚拟地址空间**。Linux中地址空间最上的区域是给操作系统中的代码和数据的，底部存放用户进程定义的代码和数据。

![虚拟地址空间](https://dreaife-1306766477.cos.ap-nanjing.myqcloud.com/%E5%B1%8F%E5%B9%95%E6%88%AA%E5%9B%BE%202023-01-15%20214623.png)

虚拟地址空间

- 程序代码和数据
  
    对所有进程而言，代码从同一固定地址开始，然后是C全局变量相对应的数据位置。
    
- 堆
  
    运行时**堆**，当调用类似`malloc`和`free`时，堆可以在运行时动态地扩展和收缩。
    
- 共享库
  
    空间的中间存放类似于C标准库和数学库的共享库代码和数据。
    
- 栈
  
    **用户栈**位于用户虚拟内存空间顶部，编译器用它实现函数调用，同样可以在运行时动态地扩展和收缩。当调用一个函数时，栈增长；一个函数返回时，栈收缩。
    
- 内核虚拟内存
  
    位于地址空间顶部。不允许应用程序读写其所在区域内容或直接调用内核代码定义的函数，必须通过内核来调用。
    

基本思想是把一个进程虚拟内存的内容存储在磁盘上，然后用主存作为磁盘的高速缓存。

## 7.4 文件

**文件**就是字节序列，每个I/O设备都可以看成文件。linux系统的输入输出都是通过使用一小组称为Unix I/O的系统函数调用读写文件来实现的。

文件向应用程序提供了一个统一的视图来看待各种I/O设备。

# 8 系统间网络通信

从单独系统来看，网络可以视为一个I/O设备。系统可以读取从其他机器发来的数据，并把数据复制到自己的主存。

![网络设备I/O](https://dreaife-1306766477.cos.ap-nanjing.myqcloud.com/%E5%B1%8F%E5%B9%95%E6%88%AA%E5%9B%BE%202023-01-15%20220432.png)

网络设备I/O

对于hello程序，我们也可以通过远程服务器来运行，通过网络与其通信，并获取返回结果。

![利用telnet通过网络远程运行hello](https://dreaife-1306766477.cos.ap-nanjing.myqcloud.com/%E5%B1%8F%E5%B9%95%E6%88%AA%E5%9B%BE%202023-01-15%20220649.png)

利用telnet通过网络远程运行hello

# 9 重要主题

## 9.1 Amdahl定律

对系统部分加速时，对系统整体响取决于该部分的重要性和加速程度。

$\alpha$为该部分时间于总时间占比，$k$为性能提升比例。

$$
T_{new}=(1-\alpha)T_{old}+(\alpha  T_{old})/k = T_{old}[(1-\alpha)+\alpha/k]
$$

计算加速比$S=T_{old}/T_{new}$

$$
S=\frac{1}{(1-\alpha)+\alpha/k}
$$

当k趋向于无穷时，

$$
S_{\infty}=\frac{1}{(1-\alpha)}
$$

## 9.2 并发和并行

并发：指一个同时具有多个活动的系统；并行：指用并发来使系统运行更快。

1. 线程级并发
   
    使用进程，可以同时让多个程序执行，从而导致并发。这种并发是模拟出来的，是一台计算机在其执行的进程间快速切换来实现，可以允许多个用户同时与系统交互、用户同时运行多个任务。
    
    **多核处理器**是将多个CPU集成到一个集成电路芯片上。
    
    ![多核处理器](https://dreaife-1306766477.cos.ap-nanjing.myqcloud.com/%E5%B1%8F%E5%B9%95%E6%88%AA%E5%9B%BE%202023-01-15%20223232.png)
    
    多核处理器
    
    **超线程**，或称同时多线程，是项允许一个CPU执行多个控制流的技术。超线程处理器可以在单个周期的基础上决定要执行哪个线程，使CPU能更好地利用其处理资源。
    
    多处理器对系统性能的提高：1.减少了多个任务模拟并发的需要；2.让应用程序运行更快（需要程序以多线程方式编写）
    
2. 指令级并行
   
    指处理器可以同时执行多条指令。处理器通过**流水线**的使用，提高了指令的执行速率。将指令执行划分成不同步骤，将处理器硬件组织成一系列阶段，每个阶段执行一个步骤。阶段并行操作，处理不同指令的不同步骤。
    
    超标量处理器—有比一个周期一条指令更快的执行速率的处理器。
    
3. 单指令、多数据并行
   
    通过处理器的特殊硬件，允许一条指令产生多个可以并行执行的操作，称为单指令、多数据，即**SIMD并行**。大多是为了提高处理影像、声音和视频数据应用的执行速度。可以使用编译器支持的特殊向量数据类型来写程序。
    

## 9.3 抽象的重要性

抽象的使用是计算机科学中最为重要的概念之一。

在处理器中，指令集架构提供对实际处理器硬件的抽象。

![计算机系统的抽象](https://dreaife-1306766477.cos.ap-nanjing.myqcloud.com/%E5%B1%8F%E5%B9%95%E6%88%AA%E5%9B%BE%202023-01-15%20224949.png)

计算机系统的抽象

虚拟机是对整个计算机的抽象，包括操作系统、处理器和程序。