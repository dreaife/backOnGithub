#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
const int N=2e5+10;
int n,k;
int cnt[N],dis[N],a[N],co[N],b[N];
void solve(){
    cin>>n>>k;int sum=0,p=1;
    memset(cnt,0,sizeof cnt);memset(dis,0,sizeof(dis));memset(co,0,sizeof(co));memset(b,-1,sizeof(b));
    for(int i=1;i<=n;i++) {cin>>a[i];cnt[a[i]]++;}
    for(int i=1;i<=n;i++) sum+=min(k,cnt[i]);sum/=k;
    for(int i=1;i<=n;i++) {dis[a[i]]++;if(dis[a[i]]>k) b[i]=0;}
    for(int i=1,j=1;i<=n;i++){
        while(b[i]==0) i++;
        b[i]=j%k;j++;b[i]++;
    }
    for(int i=1;i<=n;i++) cout<<b[i]<<' ';
    cout<<endl;
}
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int _=0;cin>>_;
    while(_--) solve();
    return 0;
}