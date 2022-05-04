#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
//const int N = 1e5+10;
//int a[N];
//int n;
string s;
void solve(){
    cin>>s;int n = s.length();
    ll ans = 0,tt = 1;
    for(int i=1;i<n;i++) tt *= 26;
    for(int i=0;i<n;i++,tt/=26){
        ans += (s[i]-'a') * tt;
    }if(s[1]>s[0]) ans -= s[0]-'a' + 1;
    else ans -= s[0]-'a';
    cout<<++ans<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int _;cin>>_;
    while(_--) solve();
    return 0;
}