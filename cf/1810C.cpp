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
int n,c,d,ans,res,tp;
//string s;
void solve(){
    cin>>n>>c>>d;ans = n * c;tp = 0;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    ans += (a[1]-1) * d-c;tp += a[1]-1;
    res = min(ans,d + n*c);
    for(int i=2;i<=n;i++) 
        if(a[i] >= i + tp){
            ans += (a[i]-a[i-1]-1)*d - c;
            tp += a[i]-a[i-1]-1;
            res = min (res , ans);
        }else tp--;
    cout<<res<<endl;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int _;cin>>_;
    while(_--) solve();
    return 0;
}
//6 2 8
//3 4 4 5 7 8
//16+10 24 16+8 18+4
//8+12