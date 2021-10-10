#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
const int N=2e5+10;
#define int ll
int a[N],n,n0;
ll sum,ans,k;
//string s;
void solve(){
    cin>>n;sum = 0;ans=0;n0=0;
    for(int i=0;i<n;i++) {cin>>a[i];sum += a[i];if(!a[i]) n0++;}
    sort(a,a+n);
    k = 2ll*sum/n;
    if((2*sum)%n) return cout<<n0*(n0-1)/2<<endl,void();
    for(int i=0;i<n;i++){
        if(2*a[i]>k) break;
        int l = i+1,r = n-1,tt=0;
        ll t = k - a[i];
        while(l<r){
            int mid = l+r>>1;
            if(a[mid]>=t) r = mid;
            else l = mid+1;
        }if(a[l] != t) continue;
        else{
            tt = l;l=i+1;r=n-1;
            while(l<r){
                int mid =l+r+1>>1;
                if(a[mid]<=t)  l = mid;
                else r = mid-1;
            }ans += l-tt+1;
        }
    }cout<<ans<<endl;
}
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int _=0;cin>>_;
    while(_--) solve();
    return 0;
}