#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
ll sum,ans;
//const int N=1e5+10;
//int q[N];
//string s;
void solve(){
    sum=0,ans=0;
    int n;cin>>n;
    for(int i=0;i<n;i++) {int t;cin>>t;sum+=t;}
    ans=n-sum%n;
    ans=ans*(n-ans);
    cout<<ans<<endl;
}
int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int _=0;cin>>_;
    while(_--) solve();
    return 0;
}