#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
#define int long long
const int N=1e5+10;
int a[N];
int ans;
//string s;
int gb(int l,int r){
    if(l>=r) return 0;
    int mid = l + r >> 1;
    int sol = gb(l,mid)+gb(mid+1,r);
    while()
}
void solve(){
    int n=0;cin>>n;
    ans=0;int p=0,t=0;
    for(int i=1;i<=n;i++) cin>>a[i],t=max(t,a[i]);
    for(int i=1;i<n;i++){
        if(a[i]>i+n) continue;
        if(a[i]*t<=2*i) continue;
        for(int j=i+1;j<=n;j++){
            if(i+j==a[i]*a[j]) ans++;
        }
    }
    cout<<ans<<endl;
}
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int _=0;cin>>_;
    while(_--) solve();
    return 0;
}