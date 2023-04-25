计算机对数字的存储由多个二进制数（位）通过不同的规则组成，本章中重点讨论无符号数、补码、浮点数。其中整数的表示为准确的，浮点数的表示为近似的。

同时，由于计算机对数字是在有限的位数中进行存储的，这会导致在数字间进行加减乘除等运算时，会出现计算结果超出限定的存储位数的情况，这种现象被称为溢出。

同时，当对于一个相同的二进制数组用不同的解释规则来解释，得出的数值也会有所不同，但它们在计算机中存储的二进制数组仍然是相同的。

# 信息存储

如第一章所说，计算机将内存抽象为一个非常打的字节数组，并命名为虚拟内存。在内存中，计算机将8位的块（字节）作为最小的可寻址内存单位，其中每位字节都由一个唯一的数字来表示其地址。

## 十六进制表示

使用十六进制（hex)来表示数，可以轻松将其转化为二进制数，也可以轻松表示一个字节的数。在c语言中，通常在其前加上0x||0X来表示。

![image-20230426002419528](https://dreaife-1306766477.cos.ap-nanjing.myqcloud.com/image-20230426002419528.png)

在十六进制和二进制相互转化时，可以根据上表，将二进制4位数直接转成十六进制，从而轻松实现进制转化。

在十六进制跟十进制转换时，则跟正常转换一样，十六进制数每位的数乘以所在第$i$位的16的$i$次幂，所算出的数的和即为转换出来的十进制。

## 字数据大小

每个计算机都会有一个字长，表明指针数据的标称大小。一个w位的计算机，虚拟地址的范围为0~$2^{w}-1$。现在常见的计算机为32位和64位，对于大多数的64位机器，32位机器编译同样可以运行，这是一种向后兼容。

机器编译指令：
```bash
gcc -m32 hello.c # 编译64位程序
gcc -m64 hello.c # 编译32位程序
```

对于不同位的机器，c所声明的数据类型其大小会有所不同：

![image-20230426003958567](https://dreaife-1306766477.cos.ap-nanjing.myqcloud.com/image-20230426003958567.png)

其中整数有符号的可以表示正负零，无符号的可以表示非负数；char表示一个单独的字节，同样可以存储整数数值；浮点数则是通过科学计数法对数进行一个近似的表示，与整数的区别在于可以表示小数并且表示范围远大于整数表示。

在编写程序的时候应该考虑到程序在不同位数的机器上运行的结果，保证程序的移植性。

## 寻址和字节顺序

对于一个对象，我们需要对其确定其地址以及内存中如何排列。对于字节排列有两个通用的规则，分别是大端法和小段法。下列是对于int的数据0x01234567的分别表示：

![image-20230426005311159](https://dreaife-1306766477.cos.ap-nanjing.myqcloud.com/image-20230426005311159.png)

存在微处理器是双端法，但是当选定操作系统后，其字节顺序也同样会固定。

字节顺序的重要表现在：

1. 不同类型机器间通过网络传输二进制数据，需要符合网络标准，防止接收数据为倒序。

2. 检查机器级程序时，通过反编译器生成的机器级代码需要根据表示顺序来确定数据的具体值。

3. 通过强制类型转换或联合来以一种数据类型来引用一个对象时，主要用在系统级编程。

   测试代码：

   ```c
   #include<stdio.h>
   
   typedef unsigned char *byte_pointer;
   
   void show_bytes(byte_pointer start,size_t len) {
       size_t i;
       for(i = 0;i<len;i++)
           printf("%.2x",start[i]);
       printf("\n");
   }
   void show_int(int x){
       show_bytes((byte_pointer) &x,sizeof(int));
   }
   void show_float(float x){
       show_bytes((byte_pointer) &x,sizeof(float));
   }
   void show_pointer(int *x){
       show_bytes((byte_pointer) &x,sizeof(void *));
   }
   void test(int val){
       int iv = val;
       float fv = (float) iv;
       int *pv = &iv;
       show_int(iv);
       show_float(fv);
       show_pointer(pv);
   }
   ```

   ![image-20230426012138811](https://dreaife-1306766477.cos.ap-nanjing.myqcloud.com/image-20230426012138811.png)

   在笔者电脑上指针的输出结果与上图中windows结果不同，主要原因为本机为64位，一字节为8位，即地址为8字节。

   ![image-20230426012629880](https://dreaife-1306766477.cos.ap-nanjing.myqcloud.com/image-20230426012629880.png)

   而观察int和float的二进制表示时，会发现二者会有一段字节相同。这是由于float是将原数据转为1+尾数f，此处float的未舍入段和原数据相同。

## 表示字符串

c语言中字符串为一个以`null`字符结尾的字符数组。常见为ASCII字符码。文本数据比二进制数据具有更强的平台独立性。

## 表示代码

程序的二进制代码很少能在不同的机器和操作系统组合之间移植。

## 布尔代数简介
