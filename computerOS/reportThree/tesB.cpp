#include<bits/stdc++.h>
using namespace std;
const int N = 10010;
int m,n,b[N],tp,c[N][N],td[N];
void init(){
    cout<<""<<endl;cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>b[i];
    }
}
int getP(int pp){
    return (pp-1)%m;
}
void run(){
    tp = 0;int f[m];
    for(int i=0;i<m;i++) f[i] = -1;
    for(int i=1;i<=n;i++){
        int p = getP(i);
        f[p] = b[i];
        for(int j=0;j<m;j++) c[j][i] = f[j];
    }
}
void print(){
    cout<<"程序运转过程"<<endl;
    cout<<setiosflags(ios::left)<<setprecision(4)<<setiosflags(ios::fixed);cout<<1;
    for(int i=1;i<=n;i++) cout<<"    "<<setw(4)<<i;cout<<endl<<endl;
    for(int i=0;i<m;i++){cout<<c[i][1];
        for(int j=2;j<=n;j++) cout<<"    "<<setw(4)<<c[i][j];
        cout<<endl;
    }int sum = 0;
    for(int i=1;i<=n;i++) if(~td[i])
        sum ++;
    cout<<endl<<sum<<'\t'<<setprecision(2)<<sum*100.0/n<<"%"<<endl;
}
int main(){
    init();
    run();
    print();
    return 0;
}