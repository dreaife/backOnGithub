#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;
typedef long long ll;
const int N = 2e5+10;
struct pt{
    int a,b;
}q[N];
int n,ans,p;
//string s;

void solve(){
    cin>>n;
    //memset(q,0,sizeof q);
    for(int i=0,t;i<n;i++){
        cin>>q[i].b;q[i].a=0;
        for(int j=0;j<q[i].b;j++){
            cin>>t;
            q[i].a=max(q[i].a,t-j);
        }
    }sort(q,q+n,[](pt t1,pt t2){return t1.a<t2.a;});ans=q[n-1].a;
    for(int i=n-2;i>=0;i--) ans=max(ans-q[i].b,q[i].a);
    cout<<ans+1<<endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int _;cin>>_;
    while(_--) solve();
    return 0;
}