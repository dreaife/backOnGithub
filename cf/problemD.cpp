#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
#define int ll
const int N = 2e5+10;
int a[N];
int n,ans;
//string s;
void solve(){
    cin>>n;cin>>a[0];
    for(int i=1;i<n;i++){
        cin>>a[i];
        ans += max(a[i],a[i-1]);
    }cout<<ans<<endl;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int _=1;
    while(_--) solve();
    return 0;
}