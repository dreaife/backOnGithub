#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
typedef long long ll;
const int N=2010;
int w[N][N],v[N];
//string s;
void solve(){
    queue<int> q;
    memset(w,0,N*N);memset(v,0,N);
    int n=0;cin>>n;
    cout<<"? 1"<<endl;cout.flush();
    for(int i=1;i<=n;i++){
        int temp=0;cin>>temp;
        if(temp==1) w[1][i]++,w[i][1]++;
        if(temp==2) q.push(i);
    }
    while(!q.empty()){
        int e=q.front(),t=0;q.pop();
        cout<<"? "<<e<<endl;cout.flush();
        for(int i=1;i<=n;i++){
            int temp=0;cin>>temp;
            if(temp==1) w[e][i]++,w[i][e]++,t++;
            if(temp==2&&!v[i]) q.push(i),v[i]++;
        }
        if(t==1){
            while()
        }
    }
    cout<<"!"<<endl;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=i;j++)
            if(w[i][j]) cout<<i<<' '<<j<<endl;
}
int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int _=0;_=1;
    while(_--) solve();
    return 0;
}