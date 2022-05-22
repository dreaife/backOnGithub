#include<bits/stdc++.h>
using namespace std;
const int N = 10010;
int m,n,b[N],tp,c[N][N],td[N];
int f[N],ck[N];
void init(){
    cout<<""<<endl;cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>b[i];
    }
}
int getP(int t){
    for(int i=0;i<m;i++) if(f[i]==t)
        return i;
    return -1;
}
void run(){
    tp = 0;
    for(int i=0;i<m;i++) f[i] = ck[i] = -1;
    for(int i= 1;i<=n;i++){
        int pp = getP(b[i]);td[i]=-1;
        if(~pp) ck[pp] = i;
        else{
            int tp = INT32_MAX,tp2 = 0;
            for(int j=0;j<m;j++) if(ck[j]<tp)
                tp = ck[j],tp2 = j;
            f[tp2] = b[i];ck[tp2] = i-1;td[i] = b[i];
        }for(int j=0;j<m;j++) c[j][i] = f[j];
    }
}
void print(){
    cout<<"LRU算法模拟程序运转过程:"<<endl;
    cout<<setiosflags(ios::left)<<setprecision(4)<<setiosflags(ios::fixed);cout<<1;
    for(int i=2;i<=n;i++) cout<<"    "<<setw(4)<<i;cout<<endl<<endl;
    for(int i=0;i<m;i++){cout<<c[i][1];
        for(int j=2;j<=n;j++) cout<<"    "<<setw(4)<<c[i][j];
        cout<<endl;
    }int sum = 0;
    for(int i=1;i<=n;i++) if(~td[i])
        sum ++;
    cout<<"\n缺页数\t缺页率\t命中率"<<endl;
    cout<<sum<<'\t'<<setprecision(2)<<sum*100.0/n<<"%\t"<<setprecision(2)<<(1-sum*1.0/n)*100<<"%"<<endl;
}
int main(){
    init();
    run();
    print();
    return 0;
}