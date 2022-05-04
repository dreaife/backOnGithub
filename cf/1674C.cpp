#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
//const int N = 1e5+10;
//int a[N];
//int n;
string s,t;
void solve(){
    cin>>s>>t;
    if(count(t.begin(),t.end(),'a'))
        if(t.length()>1) return void (cout<<-1<<endl);
        else return void(cout<<1<<endl);
    ll ans = 1;
    for(int i=0;i<s.length();i++) ans *= 2ll;
    cout<<ans<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int _;cin>>_;
    while(_--) solve();
    return 0;
}