#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
typedef long long ll;
const int N = 5010;
int a[N],b[N],sum[N];
int n,x,ans,len;
//string s;
void solve(){
    cin>>n>>x;b[0]=0;ans=0;len=0;
    for(int i=1;i<=n;i++) cin>>a[i],b[i]=b[i-1]+a[i];
    for(int l=0;l<=n;l++){int m=INT32_MIN;
        for(int i=1;i<=n-l+1;i++) m=max(m,b[i+l-1]-b[i-1]);
        sum[l]=m;
    }
    // for(int i=0;i<=n;i++) cout<<sum[i]<<' ';cout<<endl;
    for(int k=0;k<=n;k++){
        ans = INT32_MIN;
        for(int i=0;i<=n;i++) ans = max(ans,sum[i]+min(k,i)*x);
        cout<<ans<<' ';
    }cout<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int _;cin>>_;
    while(_--) solve();
    return 0;
}