#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
const int N=110;
int a[N],b[N];
void solve(){
    int n,nf=0,nz=0;cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];
    for(int i=0;i<n;i++)
        if(a[i]<b[i]) nf+=b[i]-a[i];
        else nz+=a[i]-b[i];
    if(nf!=nz) cout<<-1<<endl;
    else{
        cout<<nf<<endl;nf=0;
        for(int i=0,j=0;nf<nz;){
            while(a[i]>=b[i]) i++;
            while(a[j]<=b[j]) j++;
            cout<<j+1<<' '<<i+1<<endl;
            a[i]++;a[j]--;nf++;
        }
    }
}
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int _=0;cin>>_;
    while(_--) solve();
    return 0;
}