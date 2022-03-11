#include<iostream>
#include<cstring>
#include<algorithm>
#include<deque>
using namespace std;
typedef long long ll;
#define int ll
const int N = 2e3+10;
int a[N],b[N];
int n,os;
deque<int> ans;
//string s;
void solve(){
    cin>>n;os = 0;ans.clear();
    for(int i=1;i<=n;i++) cin>>a[i],b[a[i]]=i;
    for(int i=n;i>=1;i--){
        int t = ((b[i]-os+n)%n)%i;
        ans.push_front(t);os += t;os %= i;
    }
    while(!ans.empty()){
        cout<<ans.front()<<' ';ans.pop_front();
    }cout<<endl;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int _;cin>>_;
    while(_--) solve();
    return 0;
}