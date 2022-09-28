#include<iostream>
#include<algorithm>
using namespace std;
const int N = 1e5+10;
int n,m,x,a[N],b[N];
int main(){
    cin>>n>>m>>x;
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<m;i++) cin>>b[i];
    sort(a,a+n);sort(b,b+m);
    int l = lower_bound(a,a+n,x)-a,r = lower_bound(b,b+m,x+1)-b;
    // cout<<l<<' '<<r<<endl;
    if(l==-1) l = 0;
    else l = n - l;
    if(r == -1) r = 0;
    cout<<l+r<<endl;
    return 0;
}