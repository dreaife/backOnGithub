#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
int ans;
int n;
//string s;
void solve(){
    cin>>n;ans = 0;
    for(int i=0,t;i<n;i++) cin>>t,ans += t-1;
    if(ans%2) cout<<"errorgorn"<<endl;
    else cout<<"maomao90"<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int _;cin>>_;
    while(_--) solve();
    return 0;
}
//errorgorn 
//maomao90 