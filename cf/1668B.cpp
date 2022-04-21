#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
#define int ll
const int N = 1e5+10;
int a[N];
int n,m;
//string s;
void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    if(2*n>m) return void(cout<<"NO"<<endl);
    sort(a+1,a+1+n);
    // for(int i=1;i<=n;i++) cout<<a[i]<<' ';cout<<endl;
    for(int i=n-1,j=2*a[n]+1;i>=1;i--){
        if(j+1>m) return void(cout<<"NO"<<endl);
        j+=a[i]+1;
    }cout<<"YES"<<endl;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int _;cin>>_;
    while(_--) solve();
    return 0;
}