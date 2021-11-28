#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
//const int N = 1e5+10;
//int a[N];
int n,q,ans;
string s;
void solve(){
    int p,len;char c;
    cin>>p>>c;p--;
    len = min(n-1,p+2)-max(p-2,0)+1;
    string t = s.substr(max(p-2,0),len);
    int pos = p-max(p-2,0),cnt=0;
    for(int i=0;i<len;i++) if(t.substr(i,3) == "abc")
        cnt++;ans-=cnt;
    t[pos] = c;cnt = 0;
    for(int i=0;i<len;i++) if(t.substr(i,3) == "abc")
        cnt++;ans += cnt;
    cout<<ans<<endl;
    s[p]=c;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>q>>s;ans=0;
    for(int i=0;i<n;i++) if(s.substr(i,3) == "abc")
        ans++;
    while(q--) solve();
    return 0;
}