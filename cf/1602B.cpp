#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
typedef long long ll;
#define int ll
const int N=2010;
int a[N][N];
int n,q,x,k;
int t[N];
void solve(){
    cin>>n;memset(a,0,sizeof a);int p=0;memset(t,0,sizeof t);
    for(int i=1;i<=n;i++) cin>>a[0][i],t[a[0][i]]++;
    for(int i=1;i<=n;i++) a[1][i] = t[a[0][i]];
    for(p;p<N;p++){
        memset(t,0,sizeof t);
        for(int i=1;i<=n;i++) t[a[p][i]]++;
        for(int i=1;i<=n;i++) a[p+1][i] = t[a[p][i]];
    }p--;
    cin>>q;
    while(q--){
        cin>>x>>k;
        if(k>p) k=p;
        cout<<a[k][x]<<endl;
    }
}
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int _=0;cin>>_;
    while(_--) solve();
    return 0;
}