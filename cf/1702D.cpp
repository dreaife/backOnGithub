#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
const int N = 2e5+10;
int cnt[N];
int n,sco;
string s;
void Iprint(){
    for(int i=0;i<s.length();i++) if(!cnt[i])
        cout<<s[i];
    cout<<endl;
}
void solve(){
    cin>>s>>sco;int ans=0;
    vector<vector<int>> a(50);
    memset(cnt,0,sizeof cnt);
    for(int i=0;i<s.length();i++) a[s[i]-'a'+1].push_back(i),ans+=s[i]-'a'+1;
    if(ans <= sco) return void(cout<<s<<endl);
    for(int i=26;i>0;i--){
        if(a[i].size()==0) continue;
        if(ans-i*a[i].size() <= sco){
            for(int j=0;ans-j*i>sco;j++) cnt[a[i][j]]++;
            return void(Iprint());
        }else{
            for(int j=0;j<a[i].size();j++) cnt[a[i][j]]++;
            ans -= i*a[i].size();
        }
    }Iprint();
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int _;cin>>_;
    while(_--) solve();
    return 0;
}