#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
//const int N=1e5+10;
//int q[N];
//string s;
ll n,ans,n0;
void solve(){
    cin>>n;n0=0;ans=0;
    for(int i=0,t;i<n;i++){
        cin >> t;
        if(!t) n0++;
        if(t==1) ans++;
    }
    ans *= 1ll<<n0;
    cout<<ans<<endl;
}
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int _=0;cin>>_;
    while(_--) solve();
    return 0;
}