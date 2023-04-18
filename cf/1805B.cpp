#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
#define endl '\n'
#define all(v) v.begin(),v.end()
typedef long long ll;
typedef pair<int,int> PII;

//const int N = 2e5+10;
//int a[N];
int n,p;
string s;
void solve(){
    cin>>n>>s;
    string s1,s2;char t=s[0];p=0;
    for(int i=0;i<n;i++) if(s[i]<=t)
        t = s[i],p = i;
    if(!p) cout<<s<<endl;
    else cout<<s[p]+s.substr(0,p)+s.substr(p+1,n-p-1)<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int _;cin>>_;
    while(_--) solve();
    return 0;
}