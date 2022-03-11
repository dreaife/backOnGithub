#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
#define int ll
//const int N = 1e5+10;
//int a[N];
int n;
//string s;
void solve(){
    cin>>n;
    cout<<(2<<n-1)-1<<endl;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int _;cin>>_;
    while(_--) solve();
    return 0;
}