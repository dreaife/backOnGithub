#include<bits/stdc++.h>
using namespace std;
const int maxSize=20;
typedef struct{
    int data[maxSize+1];
    int length;
}sList;
int searchSeq(sList &a,int n){
    a.data[0]=n;
    for(int i=a.length;i>=0;i--){
        if(a.data[i]==a.data[0]){
            if(i==0) return 0;
            else return i;
        }
    }
    return 0;
}
int searchIn(sList &a,int n){
    int l=1,r=a.length;
    int mid=(l+r)/2;
    while(l<=r){
        if(a.data[mid]>n){
            r=mid-1;
            mid=(l+r)/2;
        }else if(a.data[mid]==n)
            return mid;
        else{
            l=mid+1;
            mid=(l+r)/2;
        }
    }
    return 0;
}
bool check(sList a){
    for(int i=1;i<a.length;i++)
        if(a.data[i]>a.data[i+1])
            return 0;
    return 1;
}
void menu(){
    cout<<"请输入您想进行的操作:"<<endl;
    cout<<"1.输入数列"<<endl;
    cout<<"2.进行顺序查找"<<endl;
    cout<<"3.进行折半查找"<<endl;
    cout<<"4.退出"<<endl;
}
int main(){
    sList A;
    int cho=0,k=0,pos;
    menu();
    while(cin>>cho&&cho!=4){
        switch (cho)
        {
        case 1:
            cout<<"请输入该数列长度:";
            cin>>A.length;
            for(int i=1;i<=A.length;i++)
                cin>>A.data[i];
            k=1;
            cout<<"数列创建成功！"<<endl;
            break;
        case 2:
            if(!k){
                cout<<"尚未输入数列，请先完成输入操作"<<endl;
                break;
            }
            cout<<"请输入想查找的数字:";
            pos=0;
            cin>>pos;
            pos=searchSeq(A,pos);
            if(pos) cout<<pos<<endl;
            else cout<<"该数列中无此数字"<<endl;
            break;
        case 3:
            if(!k){
                cout<<"尚未输入数列，请先完成输入操作"<<endl;
                break;
            }
            cout<<"请注意该数列为顺序数列，否则结果将会出错"<<endl;
            while(int k=check(A)&&!k){
                cout<<"您输入的数列不为升序，请重新输入"<<endl;
                break;
            }
            cout<<"请输入想查找的数字:";
            pos=0;
            cin>>pos;
            pos=searchIn(A,pos);
            if(pos) cout<<pos<<endl;
            else cout<<"该数列中无此数字"<<endl;
            break;
        default:
            cout<<"请输入正确的数字"<<endl;
            break;
        }
        cout<<endl<<"====================================================="<<endl;
        menu();
    }
    system("pause");
    return 0;
}