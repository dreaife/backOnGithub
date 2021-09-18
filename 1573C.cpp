#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
typedef long long ll;
const int N=2e5+10;
vector<vector<int>> a(N);
int n,cnt[N],ans;
//string s;
bool check(int i){
    for(int j=0;j<a[i].size();j++) if(!cnt[a[i][j]])
        return false;
    return true;
}
void solve(){
    cin>>n;memset(cnt,0,sizeof cnt);int t=n;ans=0;
    for(int i=0,p;i<n;i++){
        cin>>p;
        for(int j=0,m;j<p;j++) cin>>m,a[i].push_back(m-1);
    }int p=0;
    while(t--||p==n){
        for(int i=0;i<n;i++)
            if(!cnt[i]&&check(i)) cnt[i]++,p++;
        ans++;
    }
    if(ans!=n) cout<<-1<<endl;
    else cout<<n-t<<endl;
}
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int _=0;cin>>_;
    while(_--) solve();
    return 0;
}