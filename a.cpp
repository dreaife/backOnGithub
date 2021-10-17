#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
const int N=1e5+10;
int a[50],n,t1;
//string s;
bool check(int k){
    for(int i=0;i<n;i++) if((a[i]>>k)%2)
        return false;
    return true;
}
void solve(){
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    int k=0;
    for(k;k<N;k++) if(!check(k))
        break;t1=0;
    for(int i=0;i<n;i++) if((a[i]>>k)%2)
        t1++;
    if(t1<=1) cout<<(1<<k)<<endl;
    else cout<<(1<<(k-1))<<endl;
}
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int _=1;//cin>>_;
    while(_--) solve();
    return 0;
}