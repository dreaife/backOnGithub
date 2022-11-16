#include<iostream>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;
#define endl '\n'
#define all(v) v.begin(),v.end()
typedef long long ll;
typedef pair<int,int> PII;
#define int ll

const int N = 2e5+10;
int a[N],sum[N];
int n,ans;
//string s;
void solve(){
    cin>>n;ans=0;
    map<int,int> cnt;
    for(int i=1;i<=n;i++) cin>>a[i],sum[i]=sum[i-1]+a[i];
    for(int i=n;i>=1;--i) if(a[i]==0){
        int mx=0,pos=-1;
        for(int i=n;i>=1;--i) {
            cnt[sum[i]]++;
            mx = max(mx,cnt[sum[i]]);
            if(a[i]==0){
                // cout<<mx<<' ';
                ans += mx;
                pos = i;
                mx = 0;
                cnt.clear();
            }
        }for(int i=pos-1;i>=1;--i) if(sum[i]==0)
            ans ++;
        return void(cout<<ans<<endl);
    }
    for(int i=1;i<=n;i++) if(sum[i]==0)
        ans ++;
    cout<<ans<<endl;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int _;cin>>_;
    while(_--) solve();
    return 0;
}