#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N = 2e5+10;
ll a[N];
int n;
//string s;
void solve(){
    cin>>n;ll mx=INT64_MAX;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=n;i>=1;i-=2){
        if(a[i]<=mx){
            if(i==1) continue;
            if(a[i-1]<=mx) {mx = min({mx,a[i],a[i-1]});continue;}
        }return void(cout<<"NO"<<endl);
    }cout<<"YES"<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int _;cin>>_;
    while(_--) solve();
    return 0;
}
// 1 5 3 2
// 2    3 2     3 5 2   2 1 5 3
// 