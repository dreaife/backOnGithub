#include<iostream>
#include<fstream>
#include<algorithm>
#include<windows.h>
typedef long long ll;
using namespace std;
int a[10],b[20];
void qs(int q[],int l,int r){
    if(l>=r) return ;
    int i=l-1,j=r+1,x=q[l+r>>1];
    while(i<j){
        do i++;while(q[i]>x);
        do j--;while(q[j]<x);
        if(i<j)
            swap(q[i],q[j]);
    }
    qs(q,l,j);
    qs(q,j+1,r);
}
void print1(){
    for(int i=0;i<10;i++)
        cout<<a[i]<<' ';
    cout<<endl;
}
void print2(){
    for(int i=0;i<20;i++)
        cout<<b[i]<<' ';
    cout<<endl;
}
int main(){
    cout<<"请输入20个数据:"<<endl;
    for(int i=0;i<10;i++) cin>>a[i];
    //存储前十个数
    ofstream t1("D:\\soft learning\\c\\c++8homework\\f1.dat",ios_base::binary|ios_base::out);
    t1.write((char*)a,sizeof(a));
    t1.close();
    //存储后十个数
    for(int i=0;i<10;i++) cin>>a[i];
    ofstream t2("D:\\soft learning\\c\\c++8homework\\f2.dat",ios_base::binary|ios_base::out);
    t2.write((char*)a,sizeof(a));
    t2.close();
    //展示前十个数存储结果
    cout<<"f1.dat存储数据展示："<<endl;
    ifstream o1("D:\\soft learning\\c\\c++8homework\\f1.dat",ios_base::binary|ios_base::in);
    o1.read((char*)a,sizeof(a));
    o1.close();
    print1();
    //展示后十个数存储结果
    cout<<"f2.dat存储数据展示："<<endl;
    ifstream o2("D:\\soft learning\\c\\c++8homework\\f2.dat",ios_base::binary|ios_base::in);
    o2.read((char*)a,sizeof(a));
    o2.close();
    print1();

    ifstream o3("D:\\soft learning\\c\\c++8homework\\f1.dat",ios_base::binary|ios_base::in);
    o3.read((char*)a,sizeof(a));
    o3.close();
    qs(a,0,9);
    cout<<"f1.dat数据按降序排序后展示："<<endl;
    print1();//展示f1.dat文件数据排序后结果

    ofstream tt("D:\\soft learning\\c\\c++8homework\\f2.dat",ios_base::binary|ios_base::out|ios_base::app);
    tt.write((char*)a,sizeof(a));
    tt.close();
    ifstream o4("D:\\soft learning\\c\\c++8homework\\f2.dat",ios_base::binary|ios_base::in);
    o4.read((char*)b,sizeof(b));
    o4.close();
    cout<<"处理后的f2.dat数据展示："<<endl;
    print2();
    system("pause");
    return 0;
}
//5 6 7 8 9 0 1 2 3 4  1 2 3 4 5 6 7 8 9 10