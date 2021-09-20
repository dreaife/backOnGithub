#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
#define int ll
const int N=2e5+10;
int a[N],x,y,n,sum;
//string s;
void solve(){
    cin>>x>>y;
    int l=0,r=n-1;
    while(l<r){
        int mid=l + r >> 1;
        if(a[mid]>=x) r=mid;
        else l=mid+1;
    }
    if(a[l]!=x) cout<<"-1 -1"<<endl;
    else{
        cout<<l<<' ';
        l=0,r=n-1;
        while(l<r){
            int mid= l + r + 1 >>1;
            if(a[mid]<=x) l=mid;
            else r= mid -1;
        }
        cout<<l<<endl;
    }

}
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n;sum=0;
    for(int i=0;i<n;i++) cin>>a[i],sum+=a[i];
    sort(a,a+n);
    int _=0;//cin>>_;
    while(_--) solve();
    return 0;
}