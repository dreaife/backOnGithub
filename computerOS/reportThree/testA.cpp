#include<bits/stdc++.h>
using namespace std;
const int N = 10010;
vector<vector<int>> a;
int m,n,b[N],tp,c[N][N],td[N];
int getP(int p){
    if(p==-1) return -1;
    for(int i=0;i<a.size();i++) if(a[i][0]==p)
        return i;
    return -1;
}
int find(int d){
    int p = getP(d);if(p==-1) return INT32_MAX;
    int l = 1,r = a[p].size()-1;
    while(l<r){
        int mid = l + r >> 1;
        if(a[p][mid]>=tp) r = mid;
        else l = mid + 1;
    }if(l<a[p].size() && a[p][l] >= tp) return a[p][l] - tp;
    else return INT32_MAX/2;
}
void init(){
    cout<<""<<endl;cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>b[i];int pp = getP(b[i]);
        if(~pp) a[pp].push_back(i);
        else a.push_back({b[i],i});
    }
}
void run(){
    tp = 0;int f[m];
    for(int i=0;i<m;i++) f[i] = -1;
    for(int i=1,d;i<=n;i++){d=-1;tp = i;
        for(int j=0,ck=INT32_MIN;j<m;j++){
            if(f[j]==b[i]) {d = -1;break;}
            int ppp = find(f[j]);
            if(ppp > ck) ck = ppp,d=j;
        }if(d!=-1) f[d] = b[i];td[i]=d;
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