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
double calc(){
	double rtn = 0;
    for(int i=0;i<n;i++) rtn += 0.8*back[i].runtime;
    return rtn/n;
}
bool check(){
	for(int i=0;i<N;i++) if(!a[i].empty())
		return false;
	return true;
}
void init(){
    memset(back,0,sizeof back);
    cout<<"请输入预计运行进程数"<<endl;cin>>n;
    cout<<"请输入进程的名称、到达时间、运行时间"<<endl;
    for(int i=0;i<n;i++){
        cin>>back[i].name>>back[i].atime>>back[i].runtime;back[i].stime = -1;
    }piece = calc();
}
void runP(){
    for(int time = 0,ltime = 0,i=0;!check()||i<n;){
        if(time >= back[i].atime&&i<n){
            if(check()&&back[i].atime>=ltime) time = back[i].atime;
            a[0].push(i++);
        }
		for(int j=0;j<N;j++) if(!a[j].empty()){
			int p = a[j].front();
            if(back[p].stime == -1) back[p].stime = time;
			double tt = min(piece,back[p].runtime-back[p].worTime);
			back[p].worTime += tt;
			if(back[p].worTime == back[p].runtime){
                back[p].ftime = time + tt,a[j].pop();
                back[p].total = back[p].ftime - back[p].atime;
                back[p].weight = back[p].total/back[p].runtime;
                ltime = back[p].ftime;
            }else{
				a[min(N-1,j+1)].push(a[j].front());
				a[j].pop();
			}time += tt;
			break;
		}else if(j==N-1) time += piece;
	}
}
void print(){
    cout<<"时间片调度算法"<<endl;
    cout<<setiosflags(ios::left)<<setprecision(8)<<setiosflags(ios::fixed);
    cout<<"进程名"<<"\t\t"<<setw(15)<<"进程到达时间"<<"\t"<<setw(10)<<"进程运行时间"<<"\t"<<setw(10)<<
        "进程开始运行时间"<<"\t"<<setw(10)<<"进程完成时间"<<"\t"<<setw(10)<<"周转时间"<<"\t"<<setw(10)<<"带权周转时间"<<endl;
    // printf("进程名 \t进程到达时间 \t进程运行时间 \t进程开始运行时间 \t进程完成时间 \t周转时间 \t带权周转时间\n");
    for(int i=0;i<n;i++)
        cout<<back[i].name<<"\t\t"<<setw(15)<<back[i].atime<<"\t"<<setw(10)<<back[i].runtime<<"\t"<<setw(10)<<back[i].stime
            <<"\t\t"<<setw(10)<<back[i].ftime<<"\t"<<setw(10)<<back[i].total<<"\t"<<setw(10)<<back[i].weight<<endl;

    float sTime=0,wTime=0;
    for(int i=0;i<n;i++) sTime+=back[i].total,wTime+=back[i].weight;
    cout<<"\n平均周转时间为："<<sTime/n<<"，平均带权周转时间为："<<wTime/n<<endl;
}
int main(){
    init();
    sort(back,back+n,[](PCB t1,PCB t2){
        return t1.atime<t2.atime;
    });cout<<piece<<endl;
    runP();
    print();
    return 0;
}