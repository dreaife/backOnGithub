#include<bits/stdc++.h>
using namespace std;
const int N = 100;
double piece = 0;
class PCB{
    public:
        char name[30];          //进程名
        double atime;           //进程到达时间
        double runtime;         //进程运行时间
        double stime;           //进程开始运行时间
        double worTime;         //进程已经运行时间
        double ftime;           //进程完成时间
        double total;           //周转时间
        double weight;          //带权周转时间
};
PCB back[N];
int n,caT[N];
queue<int> a[N];
int calc(){
	sort(caT+1,caT+n+1);
	int p = n*0.8;
	return caT[p];
}
bool check(){
	for(int i=0;i<N;i++) if(!a[i].empty())
		return false;
	return true;
}
void init(){
    memset(back,0,sizeof back);
    cout<<"请输入预计运行进程数"<<endl;cin>>n;
    for(int i=0;i<n;i++){
        cout<<"请输入进程的名称、到达时间、运行时间"<<endl;
        cin>>back[i].name>>back[i].atime>>back[i].runtime;
    }piece = calc();
}
void runP(){
    int nowT = 0;
    for(int i=0;i<n;i++){
        PCB &t = back[i];
        if(nowT < t.atime) nowT = t.atime;
        t.stime = max(t.atime,(double)nowT);
        t.ftime = t.stime + t.runtime;
        t.total = t.ftime - t.atime;
        t.weight = t.total*1.0/t.runtime;
        nowT += t.runtime;

    }
    for(int time = 0,i=1;check()||i<=n;){
		for(int j=0;j<N;j++) if(!a[j].empty()){
			int p = a[j].front();
			double tt = min(piece,back[p].runtime-back[p].worTime);
			back[p].worTime += tt;
			if(back[p].worTime == back[p].runtime) back[p].ftime = time + tt,a[j].pop();
			else{
				a[min(N-1,j+1)].push(a[j].front());
				a[j].pop();
			}time += tt;
			continue;
		}if(time >= back[i].atime)
            if(!check()) time = back[i].atime,i++;
            else i++;
        time += piece;
	}
}
void print(){
    cout<<"短进程优先调度算法"<<endl;
    cout<<"进程名 进程到达时间 进程运行时间 进程开始运行时间 进程完成时间 周转时间 带权周转时间 进程优先级"<<endl;
    for(int i=0;i<n;i++)
        cout<<back[i].name<<"\t"<<back[i].atime<<"\t    "<<back[i].runtime<<"\t\t "<<back[i].stime<<"\t\t  "<<
            back[i].ftime<<"\t\t"<<back[i].total<<"\t"<<back[i].weight<<endl;

    float sTime=0,wTime=0;
    for(int i=0;i<n;i++) sTime+=back[i].total,wTime+=back[i].weight;
    cout<<"\n平均周转时间为："<<sTime/n<<"，平均带权周转时间为："<<wTime/n<<endl;
}
int main(){
    init();
    sort(back,back+n,[](PCB t1,PCB t2){
        return t1.atime<t2.atime;
    });
    runP();
    print();
    return 0;
}