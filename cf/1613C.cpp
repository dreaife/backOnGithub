#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
#define int ll
const int N = 110;
int a[N],b[N];
int n,hp;
//string s;
int get(int kp){
    int num = 0;
    for(int i=1;i<=n;i++)
        if(b[i]>kp) num += kp;
        else num += b[i];
    return num;
}
void solve(){
    cin>>n>>hp;
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=1;i<n;i++) b[i] = a[i] - a[i-1];b[n] = hp+10;
    int l=1,r=hp+10;
    while(l<r){
        int mid = l+r>>1;
        if(get(mid)>=hp) r = mid;
        else l = mid+1;
    }cout<<l<<endl;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int _;cin>>_;
    while(_--) solve();
    return 0;
}