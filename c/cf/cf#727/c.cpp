#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
const ll N=2e5+10;
ll q[N],ans=0;
//string s;
void solve(){
    ll n,k,x;
    ans=1;
    cin>>n>>k>>x;
    for(int i=0;i<n;i++) cin>>q[i];
    sort(q,q+n);
    for(int i=1;i<n;i++){
        ll t=q[i]-q[i-1];
        if(t>x) ans++;
    }
    cout<<max(ans,k)<<endl;
}
int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int _=1;
    while(_--) solve();
    return 0;
}