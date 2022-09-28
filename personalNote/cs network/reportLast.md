# 阿里云配置docker+code-server实现线上编译器

## 1. 安装docker

1. 安装Docker

Docker有两个分支版本：Docker CE和Docker EE，即社区版和企业版。本实验使用Docker CE进行操作。

- 安装Docker依赖库,添加Docker的软件源信息

```
yum install -y yum-utils device-mapper-persistent-data lvm2
yum-config-manager --add-repo http://mirrors.aliyun.com/docker-ce/linux/centos/docker-ce.repo
```

- 安装Docker

```
yum makecache fast			//更新yum缓存
yum -y install docker-ce
docker info					//查看安装状态
```

- 启动Docker服务

```
systemctl start docker			//启动docker服务
systemctl status docker			//查看docker状态
systemctl enable docker			//设置docker开机启动
```

2. 配置阿里云镜像仓库(镜像加速)

- 进入[阿里云镜像加速器界面](https://cr.console.aliyun.com/cn-hangzhou/instances/mirrors)

- 按照操作文档进行配置

```
sudo mkdir -p /etc/docker
sudo tee /etc/docker/daemon.json <<-'EOF'
{
  "registry-mirrors": ["https://0o9w7e5n.mirror.aliyuncs.com"]
}
EOF
sudo systemctl daemon-reload
sudo systemctl restart docker
```

- 配置后重新加载

```
systemctl daemon-reload			//重新加载服务配置文件
systemctl restart docker		//重启Docker服务
```

3. 通过Docker按照Nginx

- 获取最新Nginx镜像

```
docker search nginx				//查看Nginx可用版本
docker pull nginx:latest		//拉取镜像
docker images					//查看本地镜像
```

- 运行Nginx

```
docker run --name nginx-test -p 8080:80 -d nginx
```

访问8080端口，出现Nginx服务主页，运行正常。

## 2. 安装code-server

1. 安装code-server

```
curl -fOL https://github.com/cdr/code-server/releases/download/v4.4.0/code-server-4.4.0-amd64.rpm
sudo rpm -i code-server-4.4.0-amd64.rpm
sudo systemctl enable --now code-server@dreaife
```

2. 配置code-server

```
sudo systemctl enable --now code-server@dreaife				//启动coder-server服务
sudo vi ~/.config/code-server/config.yaml					//修改配置文件
sudo systemctl restart code-sercer@dreaife					//重启code-server
```

3. 将code-server部署在0.0.0.0

```
sudo vi ~/.config/code-server/config.yaml					//修改配置文件
sudo systemctl restart code-sercer@dreaife					//重启code-server
firewall-cmd --zone=public --add-port=7777/tcp --permanent	//开放端口
```

安装完成后进入code-server界面

## 3. 配置code-server编译环境

1. 通过VSIX安装code-server的C/C++组件

2. 设置.vscode的允许配置文件

- c_cpp_properties.json文件

![image-20220613170417756](https://s2.loli.net/2022/06/13/iWM4JDYnke5twCm.png)

- launch.json文件

![image-20220613170509826](https://s2.loli.net/2022/06/13/DeKW5BM21nfzgsx.png)

- tasks.json

![image-20220613170539255](https://s2.loli.net/2022/06/13/Uh2TIQKx6VwzBnp.png)

3. 测试安装结果

- 编写测试用test.cpp文件

```cpp
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
typedef long long ll;
const int N = 1e5+10;
int n,a[N];
string s;
void solve(){
    cout<<"hello"<<endl;
}
int main(){
    int _;cin>>_;
    while(_--) solve();
    return 0;
}
```

- 运行测试

![image-20220613170744067](https://s2.loli.net/2022/06/13/MaGmNUobEurdwOc.png)

运行成功，结果正确，线上编译器配置完成。