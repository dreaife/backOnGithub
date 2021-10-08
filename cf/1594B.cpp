#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
//const int N=1e5+10;
//int q[N];
//string s;
const int mod = 1000000007;
int n,k,ans;
int pow(int a,int b){
    int ans=1 ;
    while(b){
        if(b&1) ans = (1ll* ans * a)%mod;
        a = (1ll*a*a)%mod;
        b >>= 1;
    }return ans;
}
void solve(){
    cin>>n>>k;ans=0;
    int p=0;
    while(k){
        if(k&1) ans = (ans*1ll + pow(n,p))%mod;
        p++;k>>=1;
    }cout<<ans%mod<<endl;
}
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int _=0;cin>>_;
    while(_--) solve();
    return 0;
}