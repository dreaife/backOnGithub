#include<bits/stdc++.h>
using namespace std;
const int maxSize=20;
typedef struct{
    int grade;
    string name;
}student;
typedef struct{
    student data[maxSize+1];
    int length;
}sList;
void stuCout(sList &a){
    ofstream tt("stuData.txt",ios::binary|ios::out);
    tt.write((char*)&a,sizeof(a));
    tt.close();
}
void stuCin(sList &a){
    ifstream tt("stuData.txt",ios::out|ios::binary);
    while(tt.peek()!=EOF){
        tt.read((char*)&a,sizeof(a));
    }
    tt.close();
}
void swap(sList &a,int i,int j){
    swap(a.data[i].name,a.data[j].name);
    swap(a.data[i].grade,a.data[j].grade);
}
void printf(sList &a){
    for(int i=1;i<=a.length;i++){
        cout<<a.data[i].name<<'\t'<<a.data[i].grade<<endl;
    }
}
void crsort(sList &a){
    for(int i=2;i<=a.length;i++){
        if(a.data[i].grade<a.data[i-1].grade){
            a.data[0].grade=a.data[i].grade;a.data[0].name=a.data[i].name;
            a.data[i].grade=a.data[i-1].grade;a.data[i].name=a.data[i-1].name;
            int j;
            for(j=i-2;a.data[i].grade<a.data[i-1].grade;j--)
                a.data[j+1].name=a.data[j].name,a.data[j+1].grade,a.data[j].grade;
            a.data[j+1].grade=a.data[0].grade;a.data[j+1].name=a.data[0].name;
        }
    }
}
int searchIn(sList &a,int i){
    int l=1,r=i-1;
    while(l<=r){
        int mid=(l+r)/2;
        if(a.data[mid].grade>a.data[0].grade)
            r=mid-1;
        else
            l=mid+1;
    }
    return r;
}
void zbsort(sList &a){
    for(int i=2;i<=a.length;i++){
        if(a.data[i].grade<a.data[i-1].grade){
            a.data[0].grade=a.data[i].grade;a.data[0].name=a.data[i].name;
            int k=searchIn(a,i);
            for(int j=i-1;j>=k;--j)
                a.data[j+1].grade=a.data[j].grade,a.data[j+1].name=a.data[j].name;
            a.data[k+1].grade=a.data[0].grade,a.data[k+1].name=a.data[0].name;
        }
    }
}
void mpsort(sList &a){
    for(int i=a.length;i>=2;i--)
        for(int j=1;j<i;j++)
            if(a.data[j].grade>a.data[j+1].grade)
                swap(a,j,j+1);
}
void qs(sList &a,int l,int r){
    if(l>=r) return ;
    int i=l-1,j=r+1,x=a.data[(l+r)/2].grade;
    while(i<j){
        do i++;while(a.data[i].grade<x);
        do j--;while(a.data[j].grade>x);
        if(i<j)
            swap(a,i,j);
    }
    qs(a,l,j);
    qs(a,j+1,r);
}
void xzsort(sList &a){
    for(int i=1;i<=a.length;i++){
        int k=i;
        for(int j=i;j<=a.length;j++)
            if(a.data[j].grade<a.data[k].grade)
                k=j;
        swap(a,k,i);
    }
}
void menu(){
    cout<<"������������еĲ���:"<<endl;
    cout<<"1.����ѧ����Ϣ"<<endl;
    cout<<"2.���в�������"<<endl;
    cout<<"3.�����۰��������"<<endl;
    cout<<"4.����ð������"<<endl;
    cout<<"5.���п�������"<<endl;
    cout<<"6.���м�ѡ������"<<endl;
    cout<<"7.�˳�"<<endl;
}
int main(){
    sList a;
    int cho=0,k=0;
    menu();
    while(cin>>cho&&cho!=7){
        switch(cho){
            case 1:
                //����ѧ������
                cout<<"�������������ѧ��������";
                cin>>a.length;
                cout<<"�밴�������ɼ���������ѧ����Ϣ��"<<endl;
                for(int i=1;i<=a.length;i++)
                    cin>>a.data[i].name>>a.data[i].grade;
                stuCout(a);
                cout<<"ѧ����Ϣ¼��ɹ���"<<endl;
                cout<<"�������ѧ����ϢΪ��"<<endl;
                printf(a);
                cout<<endl;
                k=1;
                break;
            case 2:
                //��������
                //sList a;
                cout<<"����������Ϊ��"<<endl;
                if(!k){
                    cout<<"��δ����ѧ����Ϣ����������������"<<endl;
                    break;
                }
                stuCin(a);
                crsort(a);
                printf(a);
                cout<<endl;
                break;
            case 3:
                //�۰��������
                //sList a;
                cout<<"�۰����������Ϊ��"<<endl;
                if(!k){
                    cout<<"��δ����ѧ����Ϣ����������������"<<endl;
                    break;
                }
                stuCin(a);
                zbsort(a);
                printf(a);
                cout<<endl;
                break;
            case 4:
                //ð������
                //sList a;
                cout<<"ð������Ľ��Ϊ��"<<endl;
                if(!k){
                    cout<<"��δ����ѧ����Ϣ����������������"<<endl;
                    break;
                }
                stuCin(a);
                mpsort(a);
                printf(a);
                cout<<endl;
                break;
            case 5:
                //��������
                //sList a;
                cout<<"����������Ϊ��"<<endl;
                if(!k){
                    cout<<"��δ����ѧ����Ϣ����������������"<<endl;
                    break;
                }
                stuCin(a);
                qs(a,1,a.length);
                printf(a);
                cout<<endl;
                break;
            case 6:
                //��ѡ������
                //sList a;
                cout<<"��ѡ��������Ϊ��"<<endl;
                if(!k){
                    cout<<"��δ����ѧ����Ϣ����������������"<<endl;
                    break;
                }
                stuCin(a);
                xzsort(a);
                printf(a);
                cout<<endl;
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
//aaa 97 bbb 66 ccc 89 ddd 91