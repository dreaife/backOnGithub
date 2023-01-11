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
int l,r,x,a,b;
//string s;
void solve(){
    cin>>l>>r>>x>>a>>b;int ans = 100;
    if(a==b) ans = min(ans,0);
    if(abs(a-b) >= x) ans = min(ans,1);
    if(b-l >= x){
        if(a-l >= x) ans = min(ans,2);
        else if(r-a >= x) ans = min(ans,3);
    }
    if(r-b >= x){
        if(r-a >= x) ans = min(ans,2);
        else if(a-l >= x) ans = min(ans,3);
    }
    if(ans == 100) cout<<-1<<endl;
    else cout<<ans<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int _;cin>>_;
    while(_--) solve();
    return 0;
}