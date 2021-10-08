#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
//const int N=1e5+10;
//int q[N];
//string s;
ll n;
void solve(){
    cin>>n;
    for(ll i=1,j=1e18;i<= 1e18;i++){
        ll l=i,r=j;
        while(l<r){
            ll mid = l+r>>1;
            if((i+mid)*(mid-i+1)/2<=n) r = mid;
            else l = mid+1;
        }j = l;
        if((i+j)*(j-i+1)/2 == n) {
            cout<<i<<' '<<j<<endl;
            return ;
        }
    }
}
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int _=0;cin>>_;
    while(_--) solve();
    return 0;
}