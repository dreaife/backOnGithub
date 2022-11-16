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
int a,b,d,ans;
//string s;
int lowbit(int x){
    return x & -x;
}
void solve(){
    cin>>a>>b>>d;
    int k=0;ans = 0;
    if(lowbit(a|b) < lowbit(d))
        return void(cout<<-1<<endl);
    while((d >> k & 1) == 0) k++;
    for(int i=0;i<30;i++) if(((a|b)>>i & 1) == 1 && ((ans>>i & 1) == 0)){
        // cout<<ans<<' ';
        ans += (d <<(i-k));
    }cout<<ans<<endl;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int _;cin>>_;
    while(_--) solve();
    return 0;
}