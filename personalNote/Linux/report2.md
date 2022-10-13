# Linux实验报告二

## 一、实验要求

1. 在虚拟机中安装一个硬盘，大小为5G，然后查看自己的硬盘名称。
2. 对新安装的硬盘进行分区（命令行界面），总共分为3个区。若为MBR格式，则一个主分区，一个扩展分区，两个逻辑分区，分区大小自定义，分区类型默认。若为GPT格式，则按照顺序添加3个分区。
3. 查看分区表
4. 对各个分区建立文件系统，都建立为ext4文件系统。
5. 查看各个文件系统类型
6. 在`/mnt`文件夹下创建目录，将各个文件系统挂载在相应目录，手动挂载目录后，写入配置文件，实现自动挂载文件。



## 二、实验步骤

1. 在虚拟机中安装一个硬盘，大小为5G，然后查看自己的硬盘名称。

![image-20221007042458091](https://dreaife-1306766477.cos.ap-nanjing.myqcloud.com/image-20221007042458091.png)

输入`ls -la /dev | grep "sd"`进行查询，发现新加磁盘`sdb`已出现。

![image-20221007042728338](https://dreaife-1306766477.cos.ap-nanjing.myqcloud.com/image-20221007042728338.png)

2. 对新安装的硬盘进行分区（命令行界面），总共分为3个区。若为MBR格式，则一个主分区，一个扩展分区，两个逻辑分区，分区大小自定义，分区类型默认。若为GPT格式，则按照顺序添加3个分区。

- 查看当前磁盘格式

```shell
sudo fdisk /dev/sdb
p
```

可以看到此时磁盘为dos(MBR)格式。

![image-20221007043309967](https://dreaife-1306766477.cos.ap-nanjing.myqcloud.com/image-20221007043309967.png)

- 建立分区

```shell
n
p		# 主分区
n
e		# 扩展分区
#磁盘建满后
n		# 逻辑分区
```

![image-20221007043833274](https://dreaife-1306766477.cos.ap-nanjing.myqcloud.com/image-20221007043833274.png)

3. 查看分区表

```shell
p
```

此时可以查看分区表。

![image-20221007044129702](https://dreaife-1306766477.cos.ap-nanjing.myqcloud.com/image-20221007044129702.png)

4. 对各个分区建立文件系统，都建立为ext4文件系统。

```shell
sudo mkfs -t ext4 /dev/sdb1			# 建立ext4文件系统
sudo mkfs -t ext4 /dev/sdb5
sudo mkfs -t ext4 /dev/sdb6
```

![image-20221007045218464](https://dreaife-1306766477.cos.ap-nanjing.myqcloud.com/image-20221007045218464.png)

![image-20221007045243722](https://dreaife-1306766477.cos.ap-nanjing.myqcloud.com/image-20221007045243722.png)

5. 查看各个文件系统类型

```shell
sudo file -s /dev/sdb1				# 查看各个文件系统类型
sudo file -s /dev/sdb2
sudo file -s /dev/sdb5
sudo file -s /dev/sdb6
```

查看建立文件系统后的各个分区，其中可见sdb2为引导。

![image-20221007045427456](https://dreaife-1306766477.cos.ap-nanjing.myqcloud.com/image-20221007045427456.png)

6. 在`/mnt`文件夹下创建目录，将各个文件系统挂载在相应目录，手动挂载目录后，写入配置文件，实现自动挂载文件。

- 创建目录

```shell
cd /mnt
sudo mkdir myDisk1
sudo mkdir myDisk2
sudo mkdir myDisk3
ls -la
```

此时目录创建成功

![image-20221007045834442](https://dreaife-1306766477.cos.ap-nanjing.myqcloud.com/image-20221007045834442.png)

- 文件系统挂载

```shell
sudo mount /dev/sdb1 myDisk1
sudo mount /dev/sdb5 myDisk2
sudo mount /dev/sdb6 myDisk3
df							# 查看挂载是否成功
```

此时发现已经挂载成功。

![image-20221007050250611](https://dreaife-1306766477.cos.ap-nanjing.myqcloud.com/image-20221007050250611.png)

- 自动挂载文件

```shell
sudo nano /etc/fstab

# 写入自动挂载文件内容
# /sdb mount
/dev/sdb1 /mnt/myDisk1 ext4 errors=remount-ro O 1
/dev/sdb5 /mnt/myDisk2 ext4 errors=remount-ro 0 1
/dev/sdb6 /mnt/myDisk3 ext4 errors=remount-ro O 1
```

![image-20221007052458759](https://dreaife-1306766477.cos.ap-nanjing.myqcloud.com/image-20221007052458759.png)