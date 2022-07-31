#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
#define endl '\n'
#define all(v) v.begin(),v.end()
typedef long long ll;
typedef pair<int,int> PII;
#define int ll

const int N = 1e5+10;
int a[N],b[N];
int n,m,ans;
//string s;
void solve(){
    cin>>n>>m;ans = n;
    for(int i=0;i<m;i++) cin>>a[i];
    sort(a,a+m);
    for(int i=0;i<m;i++){
        if(!i) b[0] = n-a[m-1]+a[0]-1;
        else{
            b[i] = a[i] - a[i-1]-1;
        }
    }sort(b,b+m);
    for(int i=m-1,j=0;~i;j+=2,i--){
        if(2*j>=b[i]) continue;
        else{
            if(2*j+2>=b[i] || b[i]==1) ans--,j--;
            else ans -= b[i]-2*j-1;
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