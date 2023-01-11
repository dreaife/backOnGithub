# Linux实验报告五

## 1. 实验要求

1. 根据ppt安装LAMP环境，解释安装过程


## 2. 实验步骤

### 2.1 LAMP简介

所谓lamp，其实就是由Linux+Apache+Mysql/MariaDB+Php/Perl/Python的一组动态网站或者服务器的开源软件，除Linux外其它各部件本身都是各自独立的程序，但是因为经常被放在一起使用，拥有了越来越高的兼容度，共同组成了一个强大的Web应用程序平台。
LAMP指的是Linux（操作系统）、Apache（HTTP服务器）、MySQL（也指MariaDB，数据库软件）和PHP（有时也是指Perl或Python）的第一个字母，一般用来建立web应用平台。

### 2.2 LAMP平台搭建

#### 2.2.1 平台安装

```bash
sudo apt install lamp-server^ # lamp平台一键安装
```

- 运行代码

  ![image-20221121225645629](https://dreaife-1306766477.cos.ap-nanjing.myqcloud.com/image-20221121225645629.png)

- 测试apache

  ![image-20221121230015222](https://dreaife-1306766477.cos.ap-nanjing.myqcloud.com/image-20221121230015222.png)
  
- 测试php安装是否正确

  使用代码`sudo echo "<?php phpinfo(); ?>" > /var/www/html/test.php`将php测试代码写入Apache服务器地址根目录，并打开测试。

  ![image-20221122020507978](https://dreaife-1306766477.cos.ap-nanjing.myqcloud.com/image-20221122020507978.png)

#### 2.2.2 phpMyAdmin安装

```bash
sudo apt install phpmyadmin # phpMyAdmin安装代码
```

- 为Apache配置phpMyAdmin设置

  ![image-20221121230401149](https://dreaife-1306766477.cos.ap-nanjing.myqcloud.com/image-20221121230401149.png)

- 为phpMyAdmin配置数据

  ![image-20221121230504672](https://dreaife-1306766477.cos.ap-nanjing.myqcloud.com/image-20221121230504672.png)

- 将phpMyAdmin管理页面软连接到Apache服务器网址下

  使用代码`sudo ln -s /usr/share/phpmyadmin /var/www/html`进行连接。此时可以进入phpMyAdmin页面下进行配置。

  ![image-20221122021229860](https://dreaife-1306766477.cos.ap-nanjing.myqcloud.com/image-20221122021229860.png)

- 测试phpMyAdmin

  输入安装时注册的账号密码，进入phpMyAdmin管理界面。

  **注意：输入用户名为phpmyadmin！**

  ![image-20221122024247358](https://dreaife-1306766477.cos.ap-nanjing.myqcloud.com/image-20221122024247358.png)