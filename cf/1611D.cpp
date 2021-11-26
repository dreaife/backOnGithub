#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N = 2e5+10;
int a[N],b[N],v[N],ans[N];
int n;
//string s;
void solve(){
    cin>>n;int rt=0;
    for(int i=0;i<=n;i++) v[i]=-1,ans[i]=0;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>b[i];
    for(int i=1;i<=n;i++)
        if(a[i]==i){
            rt=i;
            if(b[1]!=i) return cout<<-1<<endl,void();
            break;
        }
    v[rt]=0;
    for(int i=2,p=0;i<=n;i++){
        int t = b[i];
        if(v[a[t]]==-1) return cout<<-1<<endl,void();
        else{
            v[t] = ++p;
            ans[t] = v[t] - v[a[t]];
        }
    }for(int i=1;i<=n;i++) cout<<ans[i]<<" \n"[i==n];
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int _;cin>>_;
    while(_--) solve();
    return 0;
}