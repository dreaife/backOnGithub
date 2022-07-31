#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
#define endl '\n'
#define all(v) v.begin(),v.end()
typedef long long ll;
typedef pair<int,int> PII;

//const int N = 2e5+10;
int cnt[2010];
int n,m;
string a,b;
void solve(){
    memset(cnt,0,sizeof cnt);
    cin>>n>>m>>a>>b;
    string t = a.substr(a.length()-b.length()+1,b.length()-1);
    if(t != b.substr(1,b.length()-1)) return void (cout<<"NO"<<endl);
    char tp = b[0];
    for(int i=0;i<a.length()-b.length()+1;i++) if(a[i] == tp){
        return void(cout<<"YES"<<endl);
    }cout<<"NO"<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int _;cin>>_;
    while(_--) solve();
    return 0;
}