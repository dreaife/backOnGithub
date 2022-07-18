#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
#define endl '\n'
#define all(v) v.begin(),v.end()
typedef long long ll;
typedef pair<int,int> PII;

//const int N = 2e5+10;
int a[100],cnt[100];
int n,m;
string s;
void solve(){
    cin>>n>>m;s = "";
    memset(cnt,0,sizeof cnt);
    for(int i=0;i<m;i++) s+="B";
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++){
        int t = min(a[i],m+1-a[i]);
        if(!cnt[t]) s[t-1] = 'A',cnt[t]++;
        else s[max(a[i],m+1-a[i])-1] = 'A';
    }cout<<s<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int _;cin>>_;
    while(_--) solve();
    return 0;
}