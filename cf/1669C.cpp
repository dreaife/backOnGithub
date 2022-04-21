#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N = 110;
int a[N];
int n,ta,tb,ans;
//string s;
void solve(){
    cin>>n;ta = tb = 0;
    for(int i=0,t;i<n;i++){
        cin>>t;t%=2;
        a[i] = t;
    }for(int i=0;i<n;i+=2) ta += a[i];
    for(int i=1;i<n;i+=2) tb += a[i];
    if((!ta||ta==((n+1)/2))&&(!tb||tb==(n/2))) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int _;cin>>_;
    while(_--) solve();
    return 0;
}