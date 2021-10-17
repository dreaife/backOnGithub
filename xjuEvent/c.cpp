#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
const int mod=1000000007;
ll n,m;
void solve(){
    cin>>n>>m;
    ll ans = 0;
    for(int i=1;i<=n+1;i++)
        for(int j=1;j<=m+1;j++)
            ans+=i+j-1;
    cout<<ans<<endl;
    //A*(n+1)+(0+...+n)*(m+1)-(n+1)*(m+1)
}
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--) solve();
    return 0;
}