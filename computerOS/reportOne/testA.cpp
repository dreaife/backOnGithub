#include<bits/stdc++.h>
using namespace std;
class PCB{
    public:
        char name;           //进程名
        int atime;           //进程到达时间
        int runtime;         //进程运行时间
        int stime;           //进程开始运行时间
        int ftime;           //进程完成时间
        int total;           //周转时间
        int special;         //进程优先级
        float weight;        //带权周转时间
};
PCB a[10];
int n,nowT;
void update(int p){
    
}
void init(){
    memset(a,0,sizeof a);
    cout<<"请输入预计运行进程数"<<endl;cin>>n;
    for(int i=0;i<n;i++){
        cout<<"请输入进程的名称、到达时间、运行时间、进程优先级"<<endl;
        cin>>a[i].name>>a[i].atime>>a[i].runtime;a[i].special=1;
    }
}
void runP(){
    nowT = 0;
    for(int i=0;i<n;i++){
        PCB &t = a[i];
        if(nowT < t.atime) nowT = t.atime;
        t.stime = max(t.atime,nowT);
        t.ftime = t.stime + t.runtime;
        t.total = t.ftime - t.atime;
        t.weight = t.total*1.0/t.runtime;
        nowT += t.runtime;

        //每回一个进程运行完成更新剩余未完成进程的优先级
        for(int j=i+1;j<n;j++) if(nowT>a[j].atime)
            a[j].special = 1 + (nowT-a[j].atime)/a[j].runtime;
        sort(a+i+1,a+n,[](PCB t1,PCB t2){
            return t1.special>t2.special;
        });
    }
}
void print(){
    cout<<"短进程优先调度算法"<<endl;
    cout<<"进程名 进程到达时间 进程运行时间 进程开始运行时间 进程完成时间 周转时间 带权周转时间 进程优先级"<<endl;
    for(int i=0;i<n;i++)
        cout<<a[i].name<<"\t"<<a[i].atime<<"\t    "<<a[i].runtime<<"\t\t "<<a[i].stime<<"\t\t  "<<
            a[i].ftime<<"\t\t"<<a[i].total<<"\t"<<a[i].weight<<"\t\t"<<a[i].special<<endl;

    float sTime=0,wTime=0;
    for(int i=0;i<n;i++) sTime+=a[i].total,wTime+=a[i].weight;
    cout<<"\n平均周转时间为："<<sTime/n<<"，平均带权周转时间为："<<wTime/n<<endl;
}
int main(){
    init();
    sort(a,a+n,[](PCB t1,PCB t2){
        return t1.atime<t2.atime;
    });
    runP();
    print();
    return 0;
}