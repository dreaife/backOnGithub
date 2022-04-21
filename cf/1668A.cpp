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
    int n,m;
    cin>>n>>m;int t=min(m,n);m=max(n,m);n=t;
    int ans = 2*(n-1) + (m-n)/2 * 4 + (m-n)%2;
    if(n==1 && m>2) return void(cout<<-1<<endl);
    cout<<ans<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int _;cin>>_;
    while(_--) solve();
    return 0;
}