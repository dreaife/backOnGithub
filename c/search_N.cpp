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
    cout<<"������������еĲ���:"<<endl;
    cout<<"1.��������"<<endl;
    cout<<"2.����˳�����"<<endl;
    cout<<"3.�����۰����"<<endl;
    cout<<"4.�˳�"<<endl;
}
int main(){
    sList A;
    int cho=0,k=0,pos;
    menu();
    while(cin>>cho&&cho!=4){
        switch (cho)
        {
        case 1:
            cout<<"����������г���:";
            cin>>A.length;
            for(int i=1;i<=A.length;i++)
                cin>>A.data[i];
            k=1;
            cout<<"���д����ɹ���"<<endl;
            break;
        case 2:
            if(!k){
                cout<<"��δ�������У���������������"<<endl;
                break;
            }
            cout<<"����������ҵ�����:";
            pos=0;
            cin>>pos;
            pos=searchSeq(A,pos);
            if(pos) cout<<pos<<endl;
            else cout<<"���������޴�����"<<endl;
            break;
        case 3:
            if(!k){
                cout<<"��δ�������У���������������"<<endl;
                break;
            }
            cout<<"��ע�������Ϊ˳�����У��������������"<<endl;
            while(int k=check(A)&&!k){
                cout<<"����������в�Ϊ��������������"<<endl;
                break;
            }
            cout<<"����������ҵ�����:";
            pos=0;
            cin>>pos;
            pos=searchIn(A,pos);
            if(pos) cout<<pos<<endl;
            else cout<<"���������޴�����"<<endl;
            break;
        default:
            cout<<"��������ȷ������"<<endl;
            break;
        }
        cout<<endl<<"====================================================="<<endl;
        menu();
    }
    system("pause");
    return 0;
}