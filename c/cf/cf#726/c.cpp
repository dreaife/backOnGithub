#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
const int N=2e5+10;
int q[N];
//string s;
void solve(){
    int n=0;cin>>n;
    for(int i=1;i<=n;i++) cin>>q[i];
    sort(q+1,q+n+1);
    int m=1e9+10;
    for(int i=2;i<=n;i++) m=min(m,abs(q[i]-q[i-1]));
        int p=0;
        for(int i=n;i>=2;i--) if(q[i]-q[i-1]==m){
            p=i;break;
        }
        if(p-2<n-p){
            int t=q[p-1];
            q[n+1]=q[p];
            for(int i=p-2;i>=1;i--) q[i+2]=q[i];
            q[2]=t;
            for(int i=2;i<=n+1;i++) cout<<q[i]<<' ';
            cout<<endl;
        }else{
            int temp[N],k=2;
            temp[1]=q[p-1];temp[n]=q[p];
            for(int i=p+1;i<=n;i++) temp[k++]=q[i];
            for(int i=1;i<p-1;i++) temp[k++]=q[i];
            for(int i=1;i<=n;i++) cout<<temp[i]<<' ';
            cout<<endl;
        }
}
int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int _=0;cin>>_;
    while(_--) solve();
    return 0;
}