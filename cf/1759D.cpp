#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
#define endl '\n'
#define all(v) v.begin(),v.end()
typedef long long ll;
typedef pair<int,int> PII;
#define int ll

//const int N = 2e5+10;
//int a[N];
int n,m,ans;
int n21,n51,n22,n52;
//string s;
void solve(){
    cin>>n>>m;
    ans = n;int tp = 0;
    for(int i=0;i<31;i++){
        int t = 1ll << i;
        for(int j=t;j<=m;j*=5){
            int x = n * (m/j * j),cnt = 0;
            for(int k=x;k % 10 == 0;k/=10) cnt++;
            if(cnt > tp || (cnt==tp && x > ans))
                ans = x,tp = cnt;
        }
    }cout<<ans<<endl;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int _;cin>>_;
    while(_--) solve();
    return 0;
}