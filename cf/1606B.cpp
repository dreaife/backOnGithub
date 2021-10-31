#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
//const int N=1e5+10;
//int q[N];
//string s;
ll n,k;
void solve(){
    cin>>n>>k;n--;
    if(!n) return cout<<0<<endl,void();
    ll t=1,cnt=1;n--;
    while(n>0){
        if(t*2ll < k) cnt++,t *= 2ll,n-=t;
        else{
            cnt += n/k;
            if(n%k) cnt++;
            break;
        }
    }cout<<max(0ll,cnt)<<endl;
}
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int _=0;cin>>_;
    while(_--) solve();
    return 0;
}