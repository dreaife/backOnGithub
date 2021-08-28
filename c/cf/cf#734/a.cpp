#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
//const int N=1e5+10;
//int q[N];
//string s;
ll n;
int c1,c2;
void solve(){
    cin>>n;
    c1=n/3;c2=c1;
    if(n%3==1) cout<<c1+1<<' '<<c2<<endl;
    else if(n%3==2) cout<<c1<<' '<<c2+1<<endl;
    else cout<<c1<<' '<<c2<<endl;
}
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int _=0;cin>>_;
    while(_--) solve();
    return 0;
}