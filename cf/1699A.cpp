#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
//const int N = 1e5+10;
//int a[N];
//int n;
//string s;
void solve(){
    int ans;cin>>ans;
    if(ans%2) cout<<-1<<endl;
    else cout<<"0 "<<ans/2<<' '<<ans/2<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int _;cin>>_;
    while(_--) solve();
    return 0;
}