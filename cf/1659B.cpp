#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N = 2e5+10;
char a[N];
int f[N];
int n,k;
//string s;
void solve(){
    cin>>n>>k;
    memset(f,0,sizeof f);
    int p=-1;for(int i=1;i<=n;i++) {
        cin>>a[i];if(p==-1&&a[i]=='1') p=i;
    }if(p==-1) p=n;
    if(k%2) {
        for(int i=1;i<=n;i++) {
            if(i==p) continue;
            a[i]=(a[i]-'0')^1 + '0';
        }k--;f[p]++;
    }
    for(int i=1;i<=n;i++){
        if(a[i]=='0'&&k){
            f[i]=1;a[i]='1';k--;
        }if(i==n) f[i]+=k;
    }if(k%2) a[n]=(a[n]-'0')^1 + '0';
    for(int i=1;i<=n;i++) cout<<a[i];cout<<endl;
    for(int i=1;i<=n;i++) cout<<f[i]<<' ';cout<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int _;cin>>_;
    while(_--) solve();
    return 0;
}