#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
int n,ans;
//const int N=1e5+10;
//int q[N];
//string s;
void solve(){
    ans=0;
    cin>>n;
    while(n){
        int t=n%10;n/=10;
        ans=max(ans,t);
    }
    cout<<ans<<endl;
}
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int _=0;cin>>_;
    while(_--) solve();
    return 0;
}