#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
#define int ll
//const int N=1e5+10;
//int q[N];
//string s;
void solve(){
    int xa,xb,xf,ya,yb,yf;
    cin>>xa>>ya>>xb>>yb>>xf>>yf;
    int ans=abs(ya-yb)+abs(xa-xb);
    if((xa==xb&&xb==xf&&((ya<yf&&yb>yf)||(yb<yf&&ya>yf)))||(ya==yb&&yb==yf&&((xa<xf&&xb>xf)||(xb<xf&&xa>xf)))) cout<<ans+2<<endl;
    else cout<<ans<<endl;
}
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int _=0;cin>>_;
    while(_--) solve();
    return 0;
}