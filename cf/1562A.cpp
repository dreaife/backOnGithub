#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
//const int N=1e5+10;
//int q[N];
//string s;
void solve(){
    int l,r;
    cin>>l>>r;
    if(l<=r/2+1) cout<<r-r/2-1<<endl;
    else cout<<r-l<<endl;
}
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int _=0;cin>>_;
    while(_--) solve();
    return 0;
}