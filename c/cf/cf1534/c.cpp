#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
const int N=4e5+10;
const ll mod = 1e9+7;
int a[N],b[N],c[N],v[N],n;
ll ans=0;
//string s;
void solve(){
    ans=1;n=0;
    int k=0;cin>>n;
    memset(v,0,N);
    for(int i=0;i<n;i++) cin>>a[i],a[i]--;
    for(int i=0;i<n;i++) cin>>b[i],b[i]--;
    for(int i=0;i<n;i++) c[a[i]]=b[i];
    for(int i=0;i<n;i++){
        if(v[i]) continue;
        int j=i;
        while(!v[j]){
            v[j]=1;
            j=c[j];
        }
        ans=ans*2%mod;
    }
    cout<<ans%mod<<endl;
}
int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int _=0;cin>>_;
    while(_--) solve();
    return 0;
}