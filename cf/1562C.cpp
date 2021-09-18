#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
//const int N=1e5+10;
//int q[N];
string s;
int n,num[10];
void solve(){
    cin>>n>>s;memset(num,0,sizeof num);
    for(int i=0;i<n;i++) if(s[i]=='0'){
        if(i<n/2) cout<<i+1<<' '<<n<<' '<<i+2<<' '<<n<<endl;
        else cout<<1<<' '<<i+1<<' '<<1<<' '<<i<<endl;
        return;
    }cout<<1<<' '<<n/2<<' '<<2<<' '<<n/2+1<<endl;
}
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int _=0;cin>>_;
    while(_--) solve();
    return 0;
}