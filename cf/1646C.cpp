#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
#define int ll
//const int N = 1e5+10;
int as[20];
int n,ans,s;
//string s;
int check(int a){
    int p=0,tp=s;
    if(a>tp) return 0;
    else if(a==tp) return ans-1;
    tp-=a;p++;
    while(tp){
        if(tp&1) p++;
        tp>>=1;
    }return ans-p;
}
void solve(){
    cin>>n;ans=0;s=n;
    while(s){
        if(s&1) ans++;
        s>>=1;
    }s=n;
    for(int i=1;i<=15;i++){
        if(as[i]>s) break;
        int t = check(as[i]);
        if(t>0) ans-=t,s-=t;
    }cout<<ans<<endl;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    memset(as,0,sizeof as);as[0]=1;
    for(int i=1;i<=15;i++) as[i]=as[i-1]*i;//cout<<as[i]<<' ';
    int _;cin>>_;
    while(_--) solve();
    return 0;
}