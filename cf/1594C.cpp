#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
//const int N=1e5+10;
//int q[N];
char a;
string s;
int n;
void solve(){
    cin>>n>>a;
    cin>>s;
    int ans=0,t=0;
    for(int i=0;i<n;i++) if(s[i]==a)
        t++;
    if(t == n) {cout<<0<<endl;return ;}
    for(int i=n/2;i<n;i++) if(s[i]==a)
        return cout<<1<<endl<<i+1<<endl,void();
    cout<<2<<endl<<n-1<<' '<<n<<endl;
}
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int _=0;cin>>_;
    while(_--) solve();
    return 0;
}