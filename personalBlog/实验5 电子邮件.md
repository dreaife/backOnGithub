# <center>实验5 电子邮件</center>

<center>班级：软件20-29		学号：20192302201		姓名：何庆晟</center>

## **1．实验目的**

- 理解电子邮件系统基本结构

- 理解客户端和服务器端，以及服务器之间的通信

- 分析理解SMTP，POP3协议

## **2．实验环境**

- 硬件要求：阿里云云主机ECS 一台。

- 软件要求：Linux/ Windows 操作系统

## **3．实验内容**

### **3.1** **使用邮件代理收发邮件**

配置邮件用户代理（例如`windows` `Outlook` `Express`，`linux` 雷鸟软件等；可以使用系统自带，也可以自行下载。），实现本地撰写，收取自己的QQ邮件。

### **3.2** **本地收发邮件**

利用本地客户端撰写和发送QQ电子邮件。同时利用`Wireshark`抓包分析其通信过程和通信协议。

### **3.3** **web邮件**

利用浏览器登录QQ邮箱，撰写和发送QQ电子邮件。同时利用`Wireshark`抓包分析其通信过程和通信协议。

### **3.4** **telnet收发邮件**

利用`telnet`命令登陆QQ邮件服务器，发送电子邮件。同时利用`Wireshark`抓包分析其通信过程和通信协议。

具体操作命令和端口查询自行网络资料解决。

## **4．实验结果与分析**

### **4.1** **使用邮件代理收发邮件**

1. 进入QQ邮箱，开启POP3/SMTP服务，获取授权码。

![image-20220606163842103](https://s2.loli.net/2022/06/06/WAPvTMgEO7DYlX9.png)

2. 按照QQ邮箱给予教程，完成outlook对QQ邮箱的绑定

![image-20220606164349923](https://s2.loli.net/2022/06/06/nyDNv6BM2EXT8W4.png)

### **4.2** **本地收发邮件**

1. 关闭账号SSL

![](https://s2.loli.net/2022/06/06/pdY93TjtRnJUafk.png)

2. 使用`wireshark`对WLAN进行抓包，并发送邮件

![image-20220606175003057](https://s2.loli.net/2022/06/06/e5dzHk21IfX4xBa.png)

3. 使用`wireshark`对SMTP进行追踪

![image-20220606174709993](https://s2.loli.net/2022/06/06/L83wZDIPviyQljA.png)

4. 分析通讯过程及通讯协议

```
C: telnet imap.qq.com 25												//以telnet方式连接qq邮件服务器
S: 220 newxmesmtplogicsvrszc10.qq.com XMail Esmtp QQ Mail Server.		//连接成功，220为响应数字，后面为欢迎信息
C: EHLO DREAIFEDESKTOP													//向服务器表明身份
S: 250-newxmesmtplogicsvrszc10.qq.com | PIPELINING | SIZE 73400320 | STARTTLS | AUTH LOGIN PLAIN XOAUTH XOAUTH2 | AUTH=LOGIN | MAILCOMPRESS | 8BITMIME													//成功
C: AUTH LOGIN															//登录账号
S: 334 VXNlcm5hbWU6
C: User: ODc3MjYxNzkzQHFxLmNvbQ==										//输入账号与授权码的base64编码
S: 334 UGFzc3dvcmQ6
C: Pass: enVqbnVobWFhcnB5YmJiYg==
S: 235 Authentication successful
C: MAIL FROM: <877261793@qq.com>										//发送人邮箱
S: 250 OK
C: RCPT TO: <877261793@qq.com>											//收信人邮箱
S: 250 OK
C: DATA																	//邮件内容
S: 354 End data with <CR><LF>.<CR><LF>.
C: DATA fragment, 2429 bytes
from: <877261793@qq.com>, subject:  ,  (text/plain) (text/html)
S: 250 OK: queued as.
C: QUIT																	//发送完成并退出
S：221 Bye
```

### **4.3** **web邮件**

1. 使用`wireshark`对WLAN进行抓包，并发送邮件

![image-20220606182013478](https://s2.loli.net/2022/06/06/9yA3gaBJip5nZFx.png)

2. 使用`wireshark`对`tls/ssl`进行追踪

![](https://s2.loli.net/2022/06/06/f56VQIEgGpxHtyr.png)

3. 分析通讯过程及通讯协议

> 1. Client Hello
>
> ![image-20220606182740471](https://s2.loli.net/2022/06/06/SPGzmxOXKJpVorj.png)
>
> TLS握手过程的第一步就是客户端发起请求，主要包括了客户端生成的随机字符串(session key)，还包含了客户端所支持所支持的加密套件列表、随机数等信息。
>
> ![image-20220606182931289](https://s2.loli.net/2022/06/06/MUh98dIWNmpn1Lc.png)
>
> 2. Server Hello && Certificate
>
> ![image-20220606183211302](https://s2.loli.net/2022/06/06/Aa2ZoQi6EhGBbeR.png)
>
> 服务器收到客户端的Client Hello数据包之后，根据客户端发来的加密套件列表，选择一个加密套件，也生成一个随机字符串返回给客户端。密钥交换算法选择的是使用ECDHE_RSA，对称加密算法使用AES_128_GCM_SHA256：同时还有返回的服务器的证书信息。
>
> ![image-20220606183445887](https://s2.loli.net/2022/06/06/phEZKM1VHBfUAdt.png)
>
> 3. Server Key Exchange & Server Hello Done
>
> ![image-20220606183628735](https://s2.loli.net/2022/06/06/3RYzrJUFaiPZKAM.png)
>
> 服务器返回Server Key Exchange数据包，用于和客户端交换用于数据加密的密钥，Server Hello Done用于通知客户端已经发送用于密钥交换的数据等待客户端响应。
>
> ![image-20220606183751791](https://s2.loli.net/2022/06/06/EvhOaj35WegzYoF.png)
>
> 4. Client Key Change & Change Cipher Spec & Encrypted HandShake Message
>
> ![image-20220606183832724](https://s2.loli.net/2022/06/06/w1rncSCU9YBhsiR.png)
>
> 客户端根据服务器返回的DH数据生成DH数据发给服务器，用来生成最终的pre-master-secret。如图：
>
> ![image-20220606183947986](https://s2.loli.net/2022/06/06/7GXgdnSAIuFOCfe.png)
>
> 5. Application Data
>
> ![image-20220606184022412](https://s2.loli.net/2022/06/06/QZ9AqUsz3n7NGSw.png)
>
> 6. Change Cipher Spec & Encrypted HandShake Message
>
> ![image-20220606184102835](https://s2.loli.net/2022/06/06/TjVrHfLqJBPXeYc.png)
>
> 每隔一段时间就要更新一次会话密钥
>
> ![image-20220606184234582](https://s2.loli.net/2022/06/06/rwfkcnzlxQ1DBSL.png)

### **4.4** **telnet收发邮件**

1. 开启电脑`Telnet`并使用`wireshark`抓包

![image-20220606184530025](https://s2.loli.net/2022/06/06/DldVe27vhCkrOQ4.png)

2. 打开`cmd`进行操作

> 1. 输入telnet imap.qq.com 25
> 2. 连接服务器后输入代码如下
>
> ![image-20220606191544204](https://s2.loli.net/2022/06/06/bOlcSHmnQYNGPyq.png)
>
> 3. 邮件发送完成
>
> ![image-20220606185950581](https://s2.loli.net/2022/06/06/SGZ1ThwLfAgRnIU.png)

3. 分析通讯过程及通讯协议

```
C: telnet imap.qq.com 25												//以telnet方式连接qq邮件服务器
S: 220 newxmesmtplogicsvrszc10.qq.com XMail Esmtp QQ Mail Server.		//连接成功，220为响应数字，后面为欢迎信息
C: helo qq.com															//向服务器表明身份
S: 250-newxmesmtplogicsvrsza5.qq.com-9.22.14.83-57293480
S: 250-SIZE 73400320
S: 250 OK																//成功
C: auth login															//登录账号
S: 334 VXNlcm5hbWU6
C: User: ODc3MjYxNzkzQHFxLmNvbQ==										//输入账号与授权码的base64编码
S: 334 UGFzc3dvcmQ6
C: Pass: enVqbnVobWFhcnB5YmJiYg==
S: 235 Authentication successful
C: MAIL FROM: <877261793@qq.com>										//发送人邮箱
S: 250 OK
C: RCPT TO: <877261793@qq.com>											//收信人邮箱
S: 250 OK
C: DATA																	//邮件内容
S: 354 End data with <CR><LF>.<CR><LF>.
C: DATA fragment, 2429 bytes
from: <877261793@qq.com>, subject:  ,  (text/plain) (text/html)
S: 250 OK: queued as.
C: QUIT																	//发送完成并退出
S：221 Bye
```

## 5、实验小结

### 5.1 问题与解决办法

> - 问题
>
>   使用`Xftp`连接服务器时，出现连接错误的情况
>
>   <img src="https://s2.loli.net/2022/04/24/BCiLywHfJoUQKg3.png" alt="image-20220424184408799"  align='left'/>
>
> - 解决方法
>
>   使用校园网连接后恢复正常，排查后发现为服务器防火墙原因

### 5.2 心得体会

- 本次实验报告熟系了对SMTP协议分析过程中代码及软件的操作，以及对SMTP报文的分析与提取，实现对课上知识的印证。通过这次实验，我掌握了telnet发送邮件的具体流程与步骤，了解了常用SMTP协议分析软件的基本用法，提高了自身编程能力。
- 通过这些常用的SMTP协议分析命令操作，对SMTP协议使用时的跟踪分析，SMTP报文的结构分析，让我印证了上课所学的知识。

