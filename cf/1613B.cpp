#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N = 2e5+10;
int a[N];
int n;
//string s;
void solve(){
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a,a+n);
    for(int i=1;i<=n/2;i++) cout<<a[i]<<' '<<a[0]<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int _;cin>>_;
    while(_--) solve();
    return 0;
}