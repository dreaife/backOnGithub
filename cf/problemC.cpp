#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> PII;
#define x first
#define y second
const int N = 1010;
int c[N],w[N];
int n,m;
int ne[N],h[N],e[N],cnt;
PII f[N];
//string s;
void add (int u,int v){
    ne[++cnt] = h[u];h[u] = cnt;e[cnt] = v;
}
void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>c[i];
    for(int i=1;i<=n;i++) cin>>w[i];
    for(int i=0,u,v;i<m;i++) cin>>u>>v,add(u,v),add(v,u);
    for(int i=1;i<=n;i++){
        
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    memset(ne,-1,sizeof ne);
    int _=1;
    while(_--) solve();
    return 0;
}