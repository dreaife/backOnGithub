#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
#define int ll
//const int N = 1e5+10;
int a[20];
int ans1,ans2,n;
//string s;
bool check(int p){
    while(p%2 == 0) p/=2;
    if(p%2 && p!=1) return true;
    else return false;
}
void get(int p,int &ans2,int &ans1){
    while(p%2 == 0)
        ans2 *= 2,p/=2;
    ans1+=p;
}
void solve(){
    cin>>n;ans1 = 0;ans2 = 0;int t=1,p=0,ans=0;
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a,a+n);
    for(int i=0;i<n;i++){
        int b=a[i],c=0;
        for(int j=0;j<n;j++)
            if(i==j) continue;
            else get(a[j],b,c);
        ans = max(ans,b+c);
    }
    cout<<ans<<endl;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int _;cin>>_;
    while(_--) solve();
    return 0;
}