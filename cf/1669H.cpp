#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N = 2e5+10;
int a[N],cnt[50];
int n,k;
//string s;
void solve(){
    memset(cnt,0,sizeof cnt);
    cin>>n>>k;for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        int t = a[i],p=31;
        while(~p){
            if(t&(1<<p)) cnt[p]++;
            p--;
        }
    }int ans = 0;
    if(cnt[31]==n) ans += 1<<31;
    for(int i=30;i>=0;i--){
        if(k>=n-cnt[i]) k-=(n-cnt[i]),cnt[i]=n;
        if(cnt[i]==n) ans += 1<<i;
    }cout<<ans<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int _;cin>>_;
    while(_--) solve();
    return 0;
}