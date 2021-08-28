#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
const int N=110;
int a[N],b[N],ans[2*N];
int ap[N],bp[N];
//string s;
void solve(){
    int k,n,m,len,a0=0,b0=0;cin>>k>>n>>m;len=k;
    memset(a,0,sizeof(a));memset(b,0,sizeof(b));
    memset(ap,0,sizeof(ap));memset(bp,0,sizeof(bp));
    memset(ans,0,sizeof(ans));
    for(int i=0;i<n;i++) {cin>>a[i];if(!a[i]) ap[a0++]=i;}
    for(int i=0;i<m;i++) {cin>>b[i];if(!b[i]) bp[b0++]=i;}
    for(int k=0,i=0,j=0;k<n+m;k++){
        if(!a[i]){i++;len++;ans[k]=a[i++];}
        else if(!b[j]) {j++;len++;ans[k]=b[j++];}
        else
            if(len<=k){cout<<-1<<endl;return;}
            else{
                int ra,rb;
                for(int t=0;t<a0;t++) if(k<ap[t]) {ra=ap[t]-k;break;}
                for(int t=0;t<b0;t++) if(k<bp[t]) {rb=bp[t]-k;break;}
                if(ra<=rb&&ra||!rb) ans[k]=a[i++];
                else if(ra>rb&&rb||!ra) ans[k]=b[j++];
            }
    }
    for(int i=0;i<n+m;i++) cout<<ans[i]<<' ';
    cout<<endl;
}
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int _=0;cin>>_;
    while(_--) solve();
    return 0;
}