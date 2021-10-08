#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
#define int ll
//const int N=1e5+10;
//int q[N];
//string s;
const int mod = 1000000007;
int pow(int a,int b){
    int ans=1 ;
    while(b){
        if(b&1) ans = (1ll* ans * a)%mod;
        a = (1ll*a*a)%mod;
        b >>= 1;
    }return ans%mod;
}
void solve(){
    int k,p=1;cin>>k;
    for(int i=0;i<k;i++) p = p*2;p -= 2;
    int ans = (pow(4,p)*1ll*6ll)%mod;
    cout<<ans<<endl;
}
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int _=1;//cin>>_;
    while(_--) solve();
    return 0;
}