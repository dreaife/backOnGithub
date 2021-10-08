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
    if(s[n-1]==a&&s[n-2]==a) {cout<<1<<endl;cout<<n<<endl;return ;}
    if(s[n-1]==a&&s[n-2]!=a) {cout<<1<<endl;cout<<n<<endl;return ;}
    if(s[n-2]==a&&s[n-1]!=a) {cout<<1<<endl;cout<<n-1<<endl;return ;}
    if(s[n-1]!=a&&s[n-2]!=a) {
        for(int i=0;i<n;i++) if(s[i] == a && n%(i+1) && (n-1)%(i+1)){
            cout<<1<<endl<<i+1<<endl;return;
        }cout<<2<<endl;cout<<n-1<<' '<<n<<endl;
    }
}
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int _=0;cin>>_;
    while(_--) solve();
    return 0;
}