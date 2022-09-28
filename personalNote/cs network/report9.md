# <center>实验9 加密、数字签名与证书</center>

<center>班级：软件20-29		学号：20192302201		姓名：何庆晟</center>

## **1．实验目的**

- 了解对称加密、非对称加密体制概念
- 了解散列函数、数字签名和数字证书的概念和理论
- 掌握基于`Openssl`的对称加密、密钥对的创建和应用
- 掌握基于`Openssl`数字签名和数字证书的创建和应用

## **2．实验环境**

- 硬件要求：阿里云云主机ECS 一台。

- 软件要求：Linux/ Windows 操作系统

## **3．实验内容**

OpenSSL是一个开放源代码的软件库包，应用程序可以使用这个包来进行安全通信，避免窃听，同时确认另一端连接者的身份。这个包广泛被应用在互联网的网页服务器上。

**参考资料：**

https://www.openssl.org/

https://gitee.com/mirrors/openssl?utm_source=alading&utm_campaign=repo#download

https://www.openssl.org/

https://www.jianshu.com/p/fb2ae3dc7986

https://www.yisu.com/zixun/21796.html

#### **3.1对称加密**

安装`Openssl`，并准备任意内容的文本文档lx.txt，利用对称加密算法对lx.txt进行加密和解密操作。

**要求：要有过程描述文字，解释当前操作以及参数含义，并提供相应操作截图**

#### **3.2** **散列函数**

计算lx.txt的MD5和SHA256散列值

#### **3.3** **非对称加密**

创建2048位的公钥密码体制RSA密钥对。利用创建的公钥加密lx.txt，私钥进行解密操作

#### **3.4** **数字签名**

对文件lx.txt进行数字签名并鉴别

#### **3.5** **证书**

使用`openssl`创建自签名证书

## **4．实验结果与分析**

#### 4.1 对称加密

1. 安装`Openssl`

```
yum info openssl 	//检查openssl版本
yum update openssl  //更新openssl
```

2. 使用加密算法进行加密解密

- 创建lx.txt文件

![image-20220612193435722](https://s2.loli.net/2022/06/12/9A5TmHWvDkIqu83.png)

- 加密

```
openssl enc -e -des -in lx.txt -out lx1.txt
```

![image-20220612194506072](https://s2.loli.net/2022/06/12/PEQLCYzpkm8dOGt.png)

加密成功

- 解密

```
openssl enc -d -des -in lx1.txt -out lx1.txt
```

![image-20220612194714867](https://s2.loli.net/2022/06/12/eBMfwzKmXyCcahr.png)

解密成功

#### **4.2** **散列函数**

计算lx.txt的MD5和SHA256散列值

- 计算MD5

```
openssl md5 -out lx.txt.md5 lx.txt
cat lx.txt.md5
```

![image-20220612195309700](https://s2.loli.net/2022/06/12/XSIpCiHKY1sxRcN.png)

- 计算SHA256散列值

```
openssl sha256 -out lx.txt.sha lx.txt
cat lx.txt.sha
```

![image-20220612200140067](https://s2.loli.net/2022/06/12/32wdiMY9o1FtBTp.png)

#### **4.3** **非对称加密**

创建2048位的公钥密码体制RSA密钥对。利用创建的公钥加密lx.txt，私钥进行解密操作

```
OpenSSL> genrsa -out RsaPrivateKey.pem 2048
OpenSSL> rsa -in RsaPrivateKey.pem -pubout -out RsaPublicKey.pem
OpenSSL> rsautl -in plain.txt -out enc.txt -inkey RSAPublicKey.pem -pubin -encrypt
OpenSSL> rsautl -in enc.txt -out replain.txt -inkey RSAPrivateKey.pem -decrypt
```

![image-20220612200536275](https://s2.loli.net/2022/06/12/PZNMUg4Ss7ke1L8.png)

密匙创建完成

![image-20220612201742659](https://s2.loli.net/2022/06/12/KlN3SMRq8dEXZQ5.png)

生成公匙

![image-20220612201911223](https://s2.loli.net/2022/06/12/HzujWoMiJ2grXlV.png)

加密于解密后文件

#### **4.4** **数字签名**

对文件lx.txt进行数字签名并鉴别

```
sha1 -out digest.txt lx.txt
rsautl -sign -inkey RsaPrivateKey.pem -in digest.txt -out signT.bin
rsautl -verify -inkey RsaPublicKey.pem -pubin -keyform PEM -in signT.bin
```

![IMG_1454(20220612-204600)](https://s2.loli.net/2022/06/12/b5jAVxnSl6UYskf.jpg)

#### **4.5** **证书**

使用`openssl`创建自签名证书

```
genrsa -des3 -out ca.key 1024
rsa -in ca.key -out ca.key
req -new -x509 -key ca.key -out ca.crt -days 365
genrsa -des3 -out server.key 2048
req -new -key server.key -out server.csr
x509 -req -in server.csr -CA ca.crt -CAkey ca.key -set_serial 01 -out server.crt -days 365
```

![IMG_1455(20220612-210523)](https://s2.loli.net/2022/06/12/fdRanm3e5BElwuU.jpg)

## 5、实验小结

### 5.1 问题与解决办法

> - 问题
>
>   在进行数字签名时，运行`sha1 -out digest.txt lx.txt`命令错误。
>
> - 解决方法
>
>   该问题是因为将`sha1`指令打为`shal`导致错误，输入`sha1 -out digest.txt lx.txt`后正确。
>
> 

### 5.2 心得体会

- 本次实验报告熟系了应用OpenSSL实现对于文件的加密以及创建自签证书，实现对课上知识的印证。通过这次实验，我掌握了OpenSSL使用的具体流程，了解了常用Linux配置软件的基本用法，提高了自身编程能力。
- 通过这些常用的Linux命令操作，对OpenSSL的配置与使用，让我印证了上课所学的知识。

 