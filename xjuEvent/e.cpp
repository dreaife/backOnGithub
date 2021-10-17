#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
const int mod =1e9+7;
#define int ll
int n,m,u,v;
int calc(int x1,int y1,int x2,int y2){
    int n1=abs(y1-y2),n2=abs(x1-x2);
    ll t1 = ((((1ll+n1)%mod)*n1)%mod)/2,t2=((((1ll+n2)%mod)*n2)%mod)/2;
    return (t1*1ll*t2)%mod;
}
void solve(){
    cin>>n>>m>>u>>v;
    n%=mod;m%=mod;u%=mod;v%=mod;
    ll ans= (calc(0,n,u,v)+calc(u,n,m,v)+calc(0,v,u,0)+calc(u,v,m,0))%mod;
    cout<<ans<<endl;
}
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--) solve();
    return 0;
}
