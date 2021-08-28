#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
const int N=110;
int ans;
int n,k;
int q[N];
//string s;
void solve(){
    ans=0;cin>>n>>k;
    memset(q,0,sizeof q);
    for(int i=0;i<k;i++) {int x,y;cin>>x>>y;q[x]=y;q[y]=x;}
    for(int i=1;i<=2*n;i++) if(q[i])
}
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int _=0;cin>>_;
    while(_--) solve();
    return 0;
}