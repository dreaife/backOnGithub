#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
const int N=1010;
int n,a[N][10];
//string s;
bool check(int x,int y){
    for(int i=1;i<=n;i++)
        if(!a[i][x]&&!a[i][y]) return false;
    return true;
}
void solve(){
    cin>>n;
    for(int i=0;i<5;i++) a[0][i] = 0;
    for(int i=1;i<=n;i++)
        for(int j=0;j<5;j++)
            cin>>a[i][j],a[0][j]+=a[i][j];
    for(int i=0;i<5;i++) if(a[0][i]>=n/2)
        for(int j=0;j<i;j++) if(a[0][j]>=n/2)
            if(check(i,j)) return cout<<"YES"<<endl,void();
    return cout<<"NO"<<endl,void();
}
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int _=0;cin>>_;
    while(_--) solve();
    return 0;
}