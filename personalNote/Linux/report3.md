# **Linux****实验报告三**

## **一、实验要求**

1. 根据qq群所给文档内容以二进制形式安装apache应用

## **二、实验步骤安装**

1. 安装apt安装依赖包

`sudo apt -y install gcc g++ make libexpat1-dev libpcre3-dev`

![](https://dreaife-1306766477.cos.ap-nanjing.myqcloud.com/image-20221019230143797.png)

2. 创建安装目录

   ```bash
   sudo mkdir /usr/local/apache2
   sudo mkdir /usr/local/pcre
   #apache2是apache2安装的位置
   #pcre是apache2的依赖包安装位置
   ```

3. 下载源码包和依赖包

   ```bash
   # 源码包通常放在这个目录下
   cd /usr/local/src
   # 下载apache2源码包
   sudo wget https://dlcdn.apache.org//httpd/httpd-2.4.54.tar.gz
   # 下载apache2依赖包
   sudo wget https://dlcdn.apache.org//apr/apr-1.7.0.tar.gz
   sudo wget https://dlcdn.apache.org//apr/apr-util-1.6.1.tar.gz
   # pcre也可以用这个网址：https://nchc.dl.sourceforge.net/project/pcre/pcre/8.45/pcre-8.45.tar.gz
   sudo wget https://sourceforge.net/projects/pcre/files/pcre/8.45/pcre-8.45.tar.gz/download -O pcre-8.45.tar.gz
   # 解压apache2源码包
   sudo tar -zxvf httpd-2.4.54.tar.gz
   # 解压依赖包
   sudo tar -zxvf apr-1.7.0.tar.gz
   sudo tar -zxvf apr-util-1.6.1.tar.gz
   sudo tar -zxvf pcre-8.45.tar.gz
   # 删除压缩包
   sudo rm *.tar.gz
   # 把apr和apr-util依赖包复制到srclib下，并且复制的时候把版本号去掉
   sudo cp -a /usr/local/src/apr-1.7.0 /usr/local/src/httpd-2.4.51/srclib/apr
   sudo cp -a /usr/local/src/apr-util-1.6.1 /usr/local/src/httpd-2.4.51/srclib/apr-util
   # apr和apr-util不用安装，只安装pcre
   # 在httpd-2.4.51目录下，可以使用./configure --help | grep pcre
   # 可以看到pcre是要求安装的，同样可以使用./configure --help | grep apr来查看apr的相关信息
   cd /usr/local/src/pcre-8.45
   sudo ./configure --prefix=/usr/local/pcre
   # 编译
   sudo make
   # 执行安装pcre
   sudo make install
   # 删除make产生的文件
   sudo make clean
   ```
   
   ![](https://dreaife-1306766477.cos.ap-nanjing.myqcloud.com/image-20221019231646660.png)
   
   在httpd-2.4.45目录下，可以使用` ./configure - help | grep pcre` 命令。
   
4. 安装apache2

   ```bash
   # 进入apache源码包
   cd /usr/local/src/httpd-2.4.51
   sudo ./configure --prefix=/usr/local/apache2 --with-pcre=/usr/local/pcre --with-included-apr
   # 如果安装了pcre却还是error：Did not find working script at pcre-config
   # 则需要安装libpcre3-dev这个包是c版本的dev包
   # sudo apt install libpcre3-dev
   # 编译
   sudo make
   # 运行安装
   sudo make install
   # 清除编译产生的文件
   sudo make clean
   ```
   
5. 运行apache2

   ```bash
   # 修改配置文件，修改为本地运行
   sudo vim /usr/local/apache2/conf/httpd.conf
   # 找到ServerName
   # 进入vim之后直接输入 /ServerName 然后回车就可以直接跳转到ServerName了
   # 可以在下面看到有一行注释为 ServerName www.example.com:80
   # 在这一行的下面添加 ServerName localhost:80
   # 当然可以用sed命令来进行替换,，-i是直接替换源文件
   # # sudo sed -i 's/com:80/com:80\nServerName localhost:80/' /usr/local/apache2/conf/httpd.conf
   # 启动Apache2
   sudo /usr/local/apache2/bin/apachectl -k start
   # 停止Apache2
   sudo /usr/local/apache2/bin/apachectl -k stop
   # 重启Apache2
   sudo /usr/local/apache2/bin/apachectl -k restart
   ```

运行` sudo /usr/local/apache2/bin/apachectl -k start` 命令，访问localhost，出现"It works！"的文字，此时运行成功。

![](https://dreaife-1306766477.cos.ap-nanjing.myqcloud.com/image-20221019233537032.png)