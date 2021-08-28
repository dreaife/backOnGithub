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
    cout<<"请输入您想进行的操作:"<<endl;
    cout<<"1.输入学生信息"<<endl;
    cout<<"2.进行插入排序"<<endl;
    cout<<"3.进行折半插入排序"<<endl;
    cout<<"4.进行冒泡排序"<<endl;
    cout<<"5.进行快速排序"<<endl;
    cout<<"6.进行简单选择排序"<<endl;
    cout<<"7.退出"<<endl;
}
int main(){
    sList a;
    int cho=0,k=0;
    menu();
    while(cin>>cho&&cho!=7){
        switch(cho){
            case 1:
                //输入学生数据
                cout<<"请输入您输入的学生数量：";
                cin>>a.length;
                cout<<"请按姓名、成绩依次输入学生信息："<<endl;
                for(int i=1;i<=a.length;i++)
                    cin>>a.data[i].name>>a.data[i].grade;
                stuCout(a);
                cout<<"学生信息录入成功！"<<endl;
                cout<<"您输入的学生信息为："<<endl;
                printf(a);
                cout<<endl;
                k=1;
                break;
            case 2:
                //插入排序
                //sList a;
                cout<<"插入排序结果为："<<endl;
                if(!k){
                    cout<<"尚未输入学生信息，请先完成输入操作"<<endl;
                    break;
                }
                stuCin(a);
                crsort(a);
                printf(a);
                cout<<endl;
                break;
            case 3:
                //折半插入排序
                //sList a;
                cout<<"折半插入排序结果为："<<endl;
                if(!k){
                    cout<<"尚未输入学生信息，请先完成输入操作"<<endl;
                    break;
                }
                stuCin(a);
                zbsort(a);
                printf(a);
                cout<<endl;
                break;
            case 4:
                //冒泡排序
                //sList a;
                cout<<"冒泡排序的结果为："<<endl;
                if(!k){
                    cout<<"尚未输入学生信息，请先完成输入操作"<<endl;
                    break;
                }
                stuCin(a);
                mpsort(a);
                printf(a);
                cout<<endl;
                break;
            case 5:
                //快速排序
                //sList a;
                cout<<"快速排序结果为："<<endl;
                if(!k){
                    cout<<"尚未输入学生信息，请先完成输入操作"<<endl;
                    break;
                }
                stuCin(a);
                qs(a,1,a.length);
                printf(a);
                cout<<endl;
                break;
            case 6:
                //简单选择排序
                //sList a;
                cout<<"简单选择排序结果为："<<endl;
                if(!k){
                    cout<<"尚未输入学生信息，请先完成输入操作"<<endl;
                    break;
                }
                stuCin(a);
                xzsort(a);
                printf(a);
                cout<<endl;
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
//aaa 97 bbb 66 ccc 89 ddd 91