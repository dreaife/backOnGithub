#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
#define endl '\n'
#define all(v) v.begin(),v.end()
typedef long long ll;
typedef pair<int,int> PII;

const int N = 2e5+10;
int a[N],cnt[N];
int n,ans;
//string s;
void solve(){
    cin>>n;ans=0;
    memset(cnt,0,sizeof cnt);
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(++cnt[a[i]]==2) ans++;
    }
    for(int i=0;i<=n;i++){
        if(!ans) return void(cout<<i<<endl);
        if(--cnt[a[i]]==1) ans--;
    }

}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int _;cin>>_;
    while(_--) solve();
    return 0;
}