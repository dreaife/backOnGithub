#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
#define int ll
const int N = 2e5+10;
int res[N];
int n;ll ans;
class T{
    public:
        int x,p;
        T(int a,int b):x(a),p(b){}
        T(){x=0,p=0;}
};T a[N];
//string s;
void solve(){
    cin>>n;ans=0;
    memset(res,0,sizeof res);a[n].p=0;
    for(int i=0,p;i<n;i++) cin>>p,a[i]=T(p,i+1);
    sort(a,a+n,[](T t1,T t2){return t1.x>t2.x;});
    for(int i=0;i<n;i+=2){
        ans += a[i].x*2*(i/2+1);
        if(a[i+1].p) ans += a[i+1].x*2*(i/2+1);
        res[a[i].p] = i/2+1;
        if(a[i+1].p) res[a[i+1].p] = -i/2-1;
    }cout<<ans<<endl;
    for(int i=0;i<=n;i++) cout<<res[i]<<" \n"[i == n];
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int _;cin>>_;
    while(_--) solve();
    return 0;
}