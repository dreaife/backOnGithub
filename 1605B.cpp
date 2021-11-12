#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
//const int N = 1e5+10;
int c[1010];
vector<int> a,b;
string s;
int n,ans;
void solve(){
    a.clear();b.clear();
    memset(c,0,sizeof c);
    cin>>n>>s;ans=0;
    for(int i=0;i<n;i++) if(s[i]=='1') a.push_back(i+1),c[i+1]=1;
        else b.push_back(i+1),c[i+1]=0;
    if(a.empty()||b.empty()||a[0]>b.back()) return cout<<0<<endl,void();
    cout<<1<<endl;
    for(int i=0,j=b.size()-1;a[i]<b[j] && i<a.size() && j>=0;i++,j--) ans++;
    cout<<2*ans<<' ';
    for(int i=0;i<ans;i++) cout<<a[i]<<' ';
    for(int i=b.size()-ans;i<b.size();i++) cout<<b[i]<<' ';cout<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int _;cin>>_;
    while(_--) solve();
    return 0;
}