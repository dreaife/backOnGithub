#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int N = 2e5+10;
int n,l,r,a[N];
ll ans;
bool check(int t){
    for(int j=2;j*j<=t;j++) if(t%j==0)
        return false;
    return true;
}
void solve(){
    n=1e9;ans=0;
    for(int i=2;i<n;i++){
        if(check(i)) ans++;
    }cout<<ans<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int _=1;//cin>>_;
    while(_--) solve();
    return 0;
}