#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int n,k,sum,ans;
int a[N],b[N],c[N];
int main(){
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i],b[i]=a[i]^(a[i]+k),sum^=a[i];
    for(int i=1;i<=n;i++) c[i]^=c[i-1];

    int tp = 0;
    for(int i=1,j=0;i<=n;i++){
        tp ^= b[i];
        if(tp==0) j=i-1;
        ans = max(ans,sum^tp);
    }
    cout<<ans<<endl;
    return 0;
}