#include<iostream>
#include<algorithm>
using namespace std;
#define int long long
int x,y,a,b;
int gcd(int a,int b){return b?gcd(b,a%b):a;}
void solve(){
    cin>>a>>b>>x>>y;
    int t = gcd(a,b),f=0;
    a /= t;b /= t;
    t = a + b;
    for(int i=0;i<63;i++) if((t >> i) & 1ll){
        if(f) return void(printf("-1\n"));
        f ++;
    }
    for(int i=0;i<63;i++) if((t >> i) & 1ll)
        return void(printf("%d\n",++i));
}
signed main(){
    int T;scanf("%d",&T);
    while(T--) solve();
    return 0;
}