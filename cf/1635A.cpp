#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N = 50;
int a[N];
int n;
//string s;
void solve(){
    int ans = 0;
    memset(a,0,sizeof a);
    cin>>n;
    for(int i=0,t;i<n;i++){
        cin>>t;int m=0;
        while(t>>m) a[m]+=(t>>m++)&1;
    }
    // for(int i=0;i<50;i++) cout<<a[i]<<' ';
    for(int i=0;i<50;i++) if(a[i])
        ans+=(1<<(i-1));
    cout<<ans<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int _;cin>>_;
    while(_--) solve();
    return 0;
}