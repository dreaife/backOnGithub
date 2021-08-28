#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
const int N=2e5+10;
int q[N];
int l,r,n=0;
//string s;
int up(int p){
    int ans=0;
    for(int j=1;j<n;j++)
        for(int i=j-1;i>=0;i--)
            if(q[i]<p-q[j]) {ans+=n-i;break;}
    return ans;
}
void solve(){
    cin>>n>>l>>r;
    for(int i=0;i<n;i++) cin>>q[i];
    sort(q,q+n);
    cout<<up(l)-up(r+1)<<endl;
}
int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int _=0;cin>>_;
    while(_--) solve();
    return 0;
}