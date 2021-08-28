#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
//const int N=1e5+10;
//int q[N];
//string s;
void solve(){
    ll n,x,t;
    cin>>n>>x>>t;
    ll ans=max(0ll,n-t/x)*(t/x);
    ans+=(min(t/x-1ll,n-1)*(min(t/x,n)))/2ll;
    cout<<ans<<endl;
}
int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int _=0;cin>>_;
    while(_--) solve();
    return 0;
}