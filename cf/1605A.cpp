#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
ll a1,a2,a3;
void solve(){
    cin>>a1>>a2>>a3;
    ll ans = a1+a3-2*a2;
    ans %= 3;
    if(ans) ans=1;
    cout<<ans<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int _;cin>>_;
    while(_--) solve();
    return 0;
}