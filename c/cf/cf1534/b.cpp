#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
const int N=4e5+10;
int q[N];
ll sum=0,ans=0;
//string s;
void solve(){
    int n=0;cin>>n;
    ans=0,sum=0;
    q[0]=q[n+1]=q[n+2]=0;
    for(int i=1;i<=n;i++) cin>>q[i];
    for(int i=1;i<=n;i++){
        ll a=q[i]-q[i-1],b=q[i]-q[i+1];
        if(a>0&&b>0)
            ans+=min(a,b),q[i]=max(q[i-1],q[i+1]);
    }
    for(int i=1;i<=n+1;i++) sum+=abs(q[i]-q[i-1]);
    cout<<ans+sum<<endl;
}
int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int _=0;cin>>_;
    while(_--) solve();
    return 0;
}