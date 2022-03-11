#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
#define int ll
const int N = 2e5+10;
int a[N],b[N];
int n,ans,ax,ay,bx,by;
//string s;
void solve(){
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];
    for(int i=0,j=INT_MAX;i<n;i++) if(abs(a[0]-b[i])<j){
        ax = i;j=abs(a[0]-b[i]);
    }for(int i=n-1,j=INT_MAX;i>=0;i--) if(abs(a[n-1]-b[i])<j){
        ay = i;j=abs(a[n-1]-b[i]);
    }for(int i=0,j=INT_MAX;i<n;i++) if(abs(b[0]-a[i])<j){
        bx = i;j=abs(b[0]-a[i]);
    }for(int i=n-1,j=INT_MAX;i>=0;i--) if(abs(b[n-1]-a[i])<j){
        by = i;j=abs(b[n-1]-a[i]);
    }ans = min({abs(a[0]-b[0])+abs(a[n-1]-b[n-1]),
            abs(a[0]-b[n-1])+abs(a[n-1]-b[0]),
            abs(a[0]-b[n-1])+abs(a[n-1]-b[ay])+abs(b[0]-a[bx]),
            abs(a[0]-b[ax])+abs(b[n-1]-a[by])+abs(a[n-1]-b[0]),
            abs(a[0]-b[ax])+abs(b[0]-a[bx])+abs(a[n-1]-b[n-1]),
            abs(a[0]-b[0])+abs(a[n-1]-b[ay])+abs(b[n-1]-a[by]),
            abs(a[0]-b[ax])+abs(a[n-1]-b[ay])+abs(b[0]-a[bx])+abs(b[n-1]-a[by])});
    cout<<ans<<endl;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int _;cin>>_;
    while(_--) solve();
    return 0;
}