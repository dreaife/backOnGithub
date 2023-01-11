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
int n,ans;
// string s;
void solve(){
    cin>>n;char t;ans = -1;
    for(int i=0;i<n;i++) cin>>t,ans = max(ans,t-'a'+1);
    cout<<ans<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int _;cin>>_;
    while(_--) solve();
    return 0;
}