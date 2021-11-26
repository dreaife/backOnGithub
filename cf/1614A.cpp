#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
#define int ll
const int N = 110;
int n,l,r,k,ans;
vector<int> q;
//string s;
void solve(){
    cin>>n>>l>>r>>k;q.clear();ans=0;
    for(int i=0,t;i<n;i++) {
        cin>>t;
        if(t<=r&&t>=l)
            q.push_back(t);
    }
    ll t=0;
    sort(q.begin(),q.end());
    for(int i=0;i<q.size();i++){
        ans++;
        t+=q[i];
        if(t>k){
            ans--;
            return cout<<ans<<endl,void();
        }
    }cout<<ans<<endl;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int _;cin>>_;
    while(_--) solve();
    return 0;
}