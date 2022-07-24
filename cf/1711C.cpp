#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
#define endl '\n'
#define all(v) v.begin(),v.end()
#define int long long
typedef long long ll;
typedef pair<int,int> PII;

const int N = 1e5+10;
int a[N];
int n,m,k;
//string s;
bool calc(int wid,int len){
    int cp = 0,tp = 0,kp = 0;
    for(int i=k-1;~i;i--){
        if(a[i]/wid <2) continue;
        cp += 2;tp++;kp += a[i]/wid -2;
    }if(len>= cp && len-cp <= kp) return true;
    else if(len < cp){
        if((len % 2 && kp) || len %2==0) return true;
    }return false;
}
void solve(){
    cin>>n>>m>>k;
    ll sum=0;
    for(int i=0;i<k;i++) cin>>a[i],sum += a[i];
    if(sum < n*m)
        return void(cout<<"No"<<endl);
    sort(a,a+k);
    if(!calc(n,m) && !calc(m,n)) return void(cout<<"No"<<endl);
    cout<<"Yes"<<endl;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int _;cin>>_;
    while(_--) solve();
    return 0;
}