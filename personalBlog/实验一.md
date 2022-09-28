# Linux实验报告一

## 一、实验要求

1. 添加David与Peter两个用户，并设置家目录自动创建，修改密码。查看创建完成后的用户与用户组配置文件（/etc/passwd、/etc/shadow）
2. 建立目录“/project”, 该目录里的文件只能有David 和 Peter 两人读取、增加、删除、修改及执行，其他用户不能对该目录进行任何的访问操作，在目录下写入project.txt文件，该文件可以由David查看，修改以及执行，但Peter只能查看，无其他权限。
3. 在project.txt文件中写入一行内容，并且使用grep命令进行查找。
4. 要求：以截图+文字说明的方式提交word或者pdf文档，文字用来解释改行命令做了什么操作，命名方式：学号+姓名



## 二、实验步骤

1. 添加用户，查看用户及配置文件

- 添加avid

```shell
useradd avid -p 12345678			# 创建用户avid并设置密码为12345678
cat /etc/passwd | grep avid			# 查看用户配置文件，且该用户名中含avid
cat /etc/shadow | grep avid			# 查看用户密码配置文件，且该用户名中含avid
cat /etc/group | grep avid			# 查看用户组配置文件，且该用户组名中含avid
```

![image-20220923035226200](https://dreaife-1306766477.cos.ap-nanjing.myqcloud.com/image-20220923035226200.png)

<center>图1 avid用户查看结果</center>

- 添加Peter

```shell
useradd Peter -p asdfghjk			# 创建用户Peter并设置密码为asdfghjk
cat /etc/passwd | grep Peter			# 查看用户配置文件，且该用户名中含Peter
cat /etc/shadow | grep Peter			# 查看用户密码配置文件，且该用户名中含Peter
cat /etc/group | grep Peter			# 查看用户组配置文件，且该用户组名中含Peter
```

![image-20220923035923857](https://dreaife-1306766477.cos.ap-nanjing.myqcloud.com/image-20220923035923857.png)

<center>图2 Peter用户查看结果</center>

2. 修改文件夹、文件权限

- 创建文件夹并修改权限

```shell
sudo groupadd linuxTestA			# 创建用户组，在其中加入avid和Peter
sudo usermod -a -G linuxTestA avid
sudo usermod -a -G linuxTestA Peter
id avid;id Peter;					# 查看用户所属组别
sudo mkdir /project					# 创建/project
sudo chgrp linuxTestA /project		# 改变文件夹所属组
sudo chmod 770 /project				# 修改文件夹权限
ls -l / | grep project				# 查看修改情况
```

![image-20220923045308786](https://dreaife-1306766477.cos.ap-nanjing.myqcloud.com/image-20220923045308786.png)

![image-20220923045333572](https://dreaife-1306766477.cos.ap-nanjing.myqcloud.com/image-20220923045333572.png)

<center>图3 创建文件夹并修改权限</center>

- 创建文件并修改权限

```shell
sudo touch /project/project.txt				# 创建/project/project.txt
sudo chown avid /project/project.txt		# 改变文件所有者
sudo chgrp linuxTestA /project/project.txt	# 改变文件所属组
sudo chmod 740 /project/project.txt			# 修改文件权限
sudo ls -l /project							# 查看修改情况
```

![image-20220923050657843](https://dreaife-1306766477.cos.ap-nanjing.myqcloud.com/image-20220923050657843.png)

<center>图4 创建文件并修改权限</center>

3. 在project.txt文件中写入一行内容，并且使用grep命令进行查找。

```shell
sudo vim /project/project.txt				# 写入内容
sudo grep hello /project/project.txt		# 通过grep进行查找
```

![image-20220923051037865](https://dreaife-1306766477.cos.ap-nanjing.myqcloud.com/image-20220923051037865.png)

<center>图5 写入文件并限定查找</center>