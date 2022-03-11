#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
#define int ll
const int N = 2e5+10;
//int a[N];
int n,m,ans;
//string s;
struct As{
    int p,x,w;
};As a[N],b[N];
bool check(As a,As b){return a.w<b.w;}
bool check1(As a,As b){return a.x<b.x;}
void solve(){
    cin>>n>>m;ans=0;
    for(int i=1;i<=m;i++) a[i].p=i,cin>>a[i].x>>a[i].w;
    sort(a+1,a+m+1,check);
    for(int i=1;i<=2*n;i++) b[i].p=a[i].p,b[i].x=a[i].x,b[i].w=a[i].w,ans+=a[i].w;
    sort(b+1,b+1+2*n,check1);
    cout<<ans<<endl;
    for(int i=1,j=2*n;i<j;i++,j--) cout<<b[i].p<<' '<<b[j].p<<endl;
    cout<<endl;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int _;cin>>_;
    while(_--) solve();
    return 0;
}