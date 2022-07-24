#include<iostream>
#include<cstring>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;
#define endl '\n'
#define all(v) v.begin(),v.end()
typedef long long ll;
typedef pair<int,int> PII;

const int N = 1e4+10;
struct T{
    int uh,cnt;
}a[N];
PII fri[N];
int n,m;
//string s;
void solve(){
    cin>>n>>m;
    for(int i=0;i<n;i++) cin>>a[i].uh,a[i].cnt=0;
    for(int i=0;i<m;i++){
        int l,r;cin>>l>>r;
        a[--l].cnt++;
        a[--r].cnt++;
        fri[i]={l,r};
    }
    if(m%2==0) return void(cout<<0<<endl);
    int ans = 1e9+10;
    for(int i=0;i<n;i++)
        if(a[i].cnt%2) ans = min(ans,a[i].uh);
    for(int i=0;i<m;i++){
        int l=fri[i].first,r=fri[i].second;
        if(a[l].cnt%2==0 && a[r].cnt%2==0)
            ans = min(ans,a[l].uh+a[r].uh);
    }
    cout<<ans<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int _;cin>>_;
    while(_--) solve();
    return 0;
}