# <center>实验6 DNS协议分析与测量</center>

<center>班级：软件20-29		学号：20192302201		姓名：何庆晟</center>

## **1．实验目的**

- 了解互联网的域名结构、域名系统DNS及其域名服务器的基本概念

- 熟悉DNS协议及其报文基本组成、DNS域名解析原理

- 掌握常用DNS测量工具dig使用方法和DNS测量的基本技术

## **2．实验环境**

- 硬件要求：阿里云云主机ECS 一台。

- 软件要求：Linux/ Windows 操作系统

## **3．实验内容**

### **3.1** **查看和配置本机的DNS系统**

首先查看本机DNS服务器配置情况，其次增加一个DNS服务器：114.114.114.114或者8.8.8.8。

### **3.2** **DNS信息测量**

dig是著名的DNS软件 Bind提供的DNS分析和测量工具。Dig可以查询DNS包括NS记录，A记录，MX记录等相关信息的工具，利用它可以进行DNS测量和分析。
安装dig命令并进行以下查询和测量

```
dig www.xju.edu.cn
dig aaaa www.xju.edu.cn
dig cname  www.sohu.com 
dig www.xju.edu.cn @8.8.8.8
dig mx xju.edu.cn
dig ns xju.edu.cn @8.8.8.8
dig www.xju.edu.cn +trace                    重要
dig edu.cn +dnssec @8.8.8.8                  重要
dig edu.cn +dnssec @114.114.114.114           //解释RRSIG作用
```

参考资料：
	https://www.isc.org/bind/
	https://www.cnblogs.com/machangwei-8/p/10353216.html

### **3.3** **DNS协议分析**

使用`tcpdump`抓取DNS查询网络通信数据包,利用`wireshark`分析UDP和DNS协议数据

## **4．实验结果与分析**

### **3.1** **查看和配置本机的DNS系统**

首先查看本机DNS服务器配置情况，其次增加一个DNS服务器：`114.114.114.114`。

![image-20220606223044270](https://s2.loli.net/2022/06/06/YrGfCz3hJjMsOBN.png)

### **3.2** **DNS信息测量**

dig是著名的DNS软件 Bind提供的DNS分析和测量工具。Dig可以查询DNS包括NS记录，A记录，MX记录等相关信息的工具，利用它可以进行DNS测量和分析,下面进行以下查询和测量。

#### 1.`dig www.xju.edu.cn`

![image-20220606230427943](https://s2.loli.net/2022/06/06/8KhtSgkXpQB4L9i.png)

#### 2.`dig aaaa www.xju.edu.cn`

![image-20220606230811432](https://s2.loli.net/2022/06/06/PvYQAzmlajKfXh2.png)

#### 3.`dig cname  www.sohu.com`

![image-20220606231419335](https://s2.loli.net/2022/06/06/uU57TrN6wRJpCAz.png)

#### 4. `dig www.xju.edu.cn @8.8.8.8`

![image-20220606231646254](https://s2.loli.net/2022/06/06/sxISZ7uJ1Da6nT5.png)

#### 5. `dig mx xju.edu.cn`

![image-20220606231811646](https://s2.loli.net/2022/06/06/zgq5GRrLwtKiBoD.png)

#### 6. `dig ns xju.edu.cn @8.8.8.8`

![image-20220606231921082](https://s2.loli.net/2022/06/06/P2zQs4pTrCUHMdf.png)

#### 7. `dig www.xju.edu.cn +trace`

![image-20220606232128035](https://s2.loli.net/2022/06/06/zM4VqduAoymiegZ.png)

#### 8. `dig edu.cn +dnssec @8.8.8.8`

![image-20220606232355655](https://s2.loli.net/2022/06/06/okQfBGY58IeMnqO.png)

#### 9. `dig edu.cn +dnssec @114.114.114.114` 

![image-20220606232454005](https://s2.loli.net/2022/06/06/DvayGBOWxJbzN3u.png)

### **3.3** **DNS协议分析**

#### 1. 使用`tcpdump`对DNS查询进行抓包

![image-20220606233041033](https://s2.loli.net/2022/06/06/YnCjGS8fA9wkgh5.png)

#### 2. 利用`wireshark`进行分析

- **DNS查询UDP数据分析**

对抓包结果进行dns过滤并分析UDP数据，如下图

![image-20220606234528157](https://s2.loli.net/2022/06/06/jfvM2aVIc9Pn1qE.png)

将获取数据填入下表

| 字段名           | 字段值 | 字段信息                      |
| ---------------- | ------ | ----------------------------- |
| Source Port      | 44175  | Source Port: 44175            |
| Destination Port | 53     | Destination Port: 53          |
| Length           | 58     | Length: 58                    |
| Checksum         | 0x93d2 | Checksum: 0x93d2 [unverified] |

- DNS协议分析

DNS数据包含内容主要有：

| 字段                   | 说明                                                         |
| ---------------------- | ------------------------------------------------------------ |
| Transaction ID (2字节) | 标识字段,用于辨别DNS应答报文是哪个请求报文的响应             |
| Flags (2字节)          | 标志字段,每一位的含义不同                                    |
| QR (1bit)              | 查询/响应标志，0 为查询报文，1 为响应报文                    |
| opcode (4bit)          | 0 表示标准查询，1 表示反向查询，2 表示服务器状态请求，3-15 是保留值 |
| AA (1bit)              | 表示授权回答，该字段在应答的时候才有意义，指出给出应答的服务器是查询域名的授权解析服务器; |
| TC (1bit)              | 表示可截断的，用来指出报文比允许的长度还要长，导致被截断     |
| RD (1bit)              | 表示期望递归，该字段被请求设置，应答的时候使用的相同的值返回。如果设置了 RD，就建议域名服务器进行递归解析，递归查询的支持是可选的 |
| RA (1bit)              | 表示可用递归，该字段在应答中设置或取消，用来代表服务器是否支持递归查询 |
| ZERO (1bit)            | 全0保留字段                                                  |
| RCODE (4bit)           | 返回码，0为无差错，1为格式错误，2为域名服务器出现错误，3为域参照问题，4为查询类型不支持，5为被禁止，6~15为保留 |
| Questions (2字节)      | 问题数，通常为1                                              |
| Answer RRs (2字节)     | 资源记录数                                                   |
| Authority RRs (2字节)  | 授权资源记录数                                               |
| Additional RRs (2字节) | 额外资源记录数                                               |
| Queries (38字节)       | 查询或者响应的正文部分,分为Name Type Class                   |
| Name (34字节)          | 查询名称，这里是ping后的参数,不定长度以0结束                 |
| Type (2字节)           | 查询类型，这里是主机A记录                                    |
| Class (2字节)          | 类,IN表示Internet数据,通常为1                                |

> 1. 分析请求包
>
> ![image-20220607002056985](https://s2.loli.net/2022/06/07/Xra4QGzLukA31yq.png)
>
> | 字段名                 | 字段值                           | 字段信息                                                     |
> | ---------------------- | -------------------------------- | ------------------------------------------------------------ |
> | UDP Dst Port           | 53                               | UDP Dst Port: 53                                             |
> | IPv4 Src               | 172.16.2.146                     | IPv4 Src: 172.16.2.146                                       |
> | Transaction ID (2字节) | 0x3a3c                           | Transaction ID: 0x3a3c                                       |
> | QR (1bit)              | 0                                | 0... .... .... .... = Response: Message is a query           |
> | opcode (4bit)          | 0                                | .000 0... .... .... = Opcode: Standard query (0)             |
> | TC (1bit)              | 0                                | .... ..0. .... .... = Truncated: Message is not truncated    |
> | RD (1bit)              | 1                                | .... ...1 .... .... = Recursion desired: Do query recursively |
> | ZERO (1bit)            | 0                                | .... .... .0.. .... = Z: reserved (0)                        |
> | Questions (2字节)      | 1                                | Questions: 1                                                 |
> | Answer RRs (2字节)     | 0                                | Answer RRs: 0                                                |
> | Authority RRs (2字节)  | 0                                | Authority RRs: 0                                             |
> | Additional RRs (2字节) | 0                                | Additional RRs: 0                                            |
> | Name (34字节)          | metrichub-cn-shanghai.aliyun.com | Name: metrichub-cn-shanghai.aliyun.com                       |
> | Type (2字节)           | 1                                | Type: A (Host Address) (1)                                   |
> | Class (2字节)          | 1                                | Class: IN (0x0001)                                           |
>
> 2. 分析响应包
>
> ![image-20220607003418465](https://s2.loli.net/2022/06/07/p9zOSr862ewHbdQ.png)
>
> 其中由于Answer RRs为1，所以Answers项中出现一个结果。
>
> Answers字段可以看成一个List,集合中每项为一个资源记录,除了上面提到过的Name,Type,Class之外,还有Time to Live,Data length,Address。
>
> | 字段名       | 字段值          | 字段信息                                |
> | ------------ | --------------- | --------------------------------------- |
> | Time to live | 75              | Time to live: 75 (1 minute, 15 seconds) |
> | Data length  | 4               | Data length: 4                          |
> | Address      | 100.100.109.104 | Address: 100.100.109.104                |



## 5、实验小结

### 5.1 问题与解决办法

> - 问题
>
>   使用dig命令时，出现`-bash: dig: command not found`错误
>
>   ![image-20220606224400904](https://s2.loli.net/2022/06/06/x3Q7KLFEMD2zdTs.png)
>
> - 解决方法
>
>   此问题是由于未安装dig支持组件，默认系统中缺少bind-utils工具包，使用yum安装即可。
>
>   ```
>   yum -y install bind-utils
>   ```
>
>   

### 5.2 心得体会

- 本次实验报告熟系了对DNS协议分析过程中代码及软件的操作，以及对UDP报文的分析与提取，实现对课上知识的印证。通过这次实验，我掌握了dig命令使用中的具体流程，了解了常用DNS协议分析软件的基本用法，提高了自身编程能力。
- 通过这些常用的DNS协议分析命令操作，对DNS协议使用时的跟踪分析，DNS、UDP报文的结构分析，让我印证了上课所学的知识。

 