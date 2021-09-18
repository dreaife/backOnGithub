#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
//const int N=1e5+10;
//int q[N];
string s;
int n,ans;
void solve(){
    cin>>n>>s;ans=0;
    for(int i=0;i<n;i++){
        ans+=s[i]-'0';
        if(s[i]!='0') ans++;
    }if(s[n-1]!='0') ans--;
    cout<<ans<<endl;
}
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int _=0;cin>>_;
    while(_--) solve();
    return 0;
}