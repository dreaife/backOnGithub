#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N = 2e5+10;
int a[N],cnt;
int n,k;
//string s;
void solve(){
    cin>>n>>k;cnt=0;
    for(int i=1;i<=n;i++) cin>>a[i];
    if(k==1) return void(cout<<(n-1)/2<<endl);
    for(int i=2;i<n;i++) if(a[i]>a[i-1]+a[i+1])
        cnt++;
    cout<<cnt<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int _;cin>>_;
    while(_--) solve();
    return 0;
}