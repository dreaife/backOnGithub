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
int n;
//string s;
void solve(){
    int ans = 0;cin>>n;
    for(int i=0,t;i<n;i++) cin>>t,ans = ans ^ t;
    if(n%2) cout<<ans<<endl;
    else {
        if(ans) cout<<-1<<endl;
        else cout<<0<<endl;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int _;cin>>_;
    while(_--) solve();
    return 0;
}