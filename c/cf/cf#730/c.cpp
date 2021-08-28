#include<bits/stdc++.h>
using namespace std;
#define eps 1e-7
typedef long long ll;
typedef long double ld;
ld c,m,p,v,ans;
void dfs(ld cc,ld mm,ld pp,ld grade){
    ans+=grade;
    if(cc<eps&&mm<eps) return;
    if(cc>eps){
        if(mm>eps) dfs(cc-min(cc,v),mm+min(cc,v)/2,pp+min(cc,v)/2,grade*cc);
        else dfs(cc-min(cc,v),mm,pp+min(cc,v),grade*cc);
    }
    if(mm>eps){
        if(cc>eps) dfs(cc+min(mm,v)/2,mm-min(mm,v),pp+min(mm,v)/2,grade*mm);
        else dfs(cc,mm-min(mm,v),pp+min(mm,v),grade*mm);
    }
}
void solve(){
    ans=0;
    cin>>c>>m>>p>>v;
    dfs(c,m,p,1);
    cout<<fixed<<setprecision(12)<<ans<<endl;
}
int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int _=0;cin>>_;
    while(_--) solve();
    return 0;
}