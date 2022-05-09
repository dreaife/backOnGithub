#include<bits/stdc++.h>
using namespace std;
const int N = 1010;
struct non{         //内存分区说明表
    int id;         //分区号
    int size;       //大小(KB)
    int addr;       //起址
    int status;     //状态
    void print(){
        cout<<id<<"\t"<<size<<"\t"<<addr<<"\t"<<((status)?"true":"false")<<endl;
    }
};non a[N];
int n,opt=10;
void show(){
    cout<<"\n当前内存分配情况如下：\nid\tsize\taddress\tstatus\n";
    for(int i=1;i<=n;i++) a[i].print();
}
void init(){
    cout<<"初始化内存块\n请输入内存块个数: "<<endl;cin>>n;
    cout<<"请设置每个内存块的大小"<<endl;
    a[0].id=0;a[0].size=0;a[0].addr=0;a[0].status=0;
    for(int i=1;i<=n;i++){
        a[i].id = i;cin>>a[i].size;
        a[i].addr = a[i-1].addr+a[i-1].size;
        a[i].status = 0;
    }show();
}
int getPos(int size){
    for(int i=1;i<=n;i++) if(a[i].size>=size && !a[i].status)
        return i;
    return 0;
}
void alloc(){
    int size;cout<<"请输入想分配的作业的大小：\n";
    cin>>size;int pos = getPos(size);
    if(!pos) return void(cout<<"作业过大,分配失败"<<endl);
    a[pos].status = 1;
    cout<<"资源分配成功,其内存空间信息为"<<endl;
    cout<<"内存块号："<<a[pos].id<<", 内存大小："<<a[pos].size<<endl;
    show();
}
void recov(){
    int pos;cout<<"请输入存储该作业的内存分区说明表的ID: "<<endl;
    cin>>pos;a[pos].status = 0;
    cout<<"已释放该作业所占用的资源"<<endl;
    show();
}
int main(){
    init();
    cout<<"\n 请输入命令,给作业分配资源输入1,释放资源输入0,退出请输入-1:\n";
    while(cin>>opt&&~opt){
        if(opt){
            cout<<"请输入待分配内存的作业个数:"<<endl;cin>>opt;
            for(int i=0;i<opt;i++) alloc();
        }else{
            cout<<"请输入需要释放的作业个数:"<<endl;cin>>opt;
            for(int i=0;i<opt;i++) recov();
        }cout<<"请继续输入指令:\n";
    }cout<<"程序结束"<<endl;
    return 0;
}