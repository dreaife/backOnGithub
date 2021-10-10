#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
//const int N=1e5+10;
//int q[N];
int n;
string a,b;
void solve(){
    cin>>n>>a>>b;
    for(int i=0;i<n;i++) if(a[i]-'0'+b[i]-'0'>=2)
        return cout<<"NO"<<endl,void();
    return cout<<"YES"<<endl,void();
}
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int _=0;cin>>_;
    while(_--) solve();
    return 0;
}