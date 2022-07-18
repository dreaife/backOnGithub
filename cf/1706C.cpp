#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
#define endl '\n'
#define all(v) v.begin(),v.end()
typedef long long ll;
typedef pair<int,int> PII;

const int N = 1e5+10;
int a[N];
ll ans;
int n;
//string s;
void solve(){
    cin>>n;ans = 0;
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=1;i<n-1;i+=2) if(max(a[i-1],a[i+1])>=a[i]){
        ans += max(a[i-1],a[i+1]) - a[i] + 1;
    }
    ll res = ans;
    if(n%2==0){
        for(int i=n-2;i>=1;i--){
            if(i%2) res -= max({a[i-1]+1,a[i+1]+1,a[i]}) - a[i];
            else res += max({a[i-1]+1,a[i+1]+1,a[i]}) - a[i];
            ans = min(ans,res);
        }
    }cout<<ans<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int _;cin>>_;
    while(_--) solve();
    return 0;
}