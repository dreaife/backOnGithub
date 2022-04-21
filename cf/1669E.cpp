#include<iostream>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;
typedef long long ll;
const int N = 1e5+10;
ll n,ans;
string s,t;
map<string,int> cnt;
void solve(){
    cin>>n;ans = 0;
    cnt.clear();
    for(int i=0;i<n;i++){
        s=t="  ";cin>>s;
        for(char i='a';i<='k';i++){
            if(i!=s[0]) t[0]=i,t[1]=s[1],ans += cnt[t];
            if(i!=s[1]) t[1]=i,t[0]=s[0],ans += cnt[t];
        }cnt[s]++;
    }cout<<ans<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int _;cin>>_;
    while(_--) solve();
    return 0;
}