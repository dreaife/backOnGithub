#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
//const int N=1e5+10;
int cnt[30];
string s;
void solve(){
    cin>>s;int sum=0;
    memset(cnt,0,sizeof(cnt));
    for(int i=0;i<s.length();i++) cnt[s[i]-'a']++;
    for(int i=0;i<26;i++) sum+=min(cnt[i],2);
    cout<<sum/2<<endl;
}
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int _=0;cin>>_;
    while(_--) solve();
    return 0;
}