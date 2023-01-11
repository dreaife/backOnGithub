#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
#define endl '\n'
#define all(v) v.begin(),v.end()
typedef long long ll;
typedef pair<int,int> PII;
#define int ll

const int N = 2e5+10;
int a[N];
int n,ans,c1,c0;
//string s;
void solve(){
    cin>>n;c0 = c1 = ans = 0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]==0) ans += c1,c0++;
        else c1++;
    }int res = ans;
    for(int i=0;i<n;i++) if(a[i]==0){
            ans = max(ans,res-i+c0-1ll);
            break;
        }
    for(int i=n-1;i>=0;i--) if(a[i]==1){
            ans = max(ans,res-(n-i-1ll)+c1-1ll);
            break;
        }
    cout<<ans<<endl;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int _;cin>>_;
    while(_--) solve();
    return 0;
}