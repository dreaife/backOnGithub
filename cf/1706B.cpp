#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<unordered_map>
using namespace std;
#define endl '\n'
#define all(v) v.begin(),v.end()
typedef long long ll;
typedef pair<int,int> PII;

const int N = 2e5+10;
int a[N],ans[N];
int n;
//string s;
void solve(){
    cin>>n;
    memset(ans,0,sizeof ans);
    memset(a,0,sizeof a);
    for(int i=0;i<n;i++){
        int t;cin>>t;
        if(!ans[t] || i%2 != a[t]){
            ans[t] ++;
            a[t] = i%2;
        }
    }
    for(int i=1;i<=n;i++){
        cout<<ans[i]<<" ";
    }cout<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int _;cin>>_;
    while(_--) solve();
    return 0;
}