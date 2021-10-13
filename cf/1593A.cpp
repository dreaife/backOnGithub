#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
#define int ll
//const int N=1e5+10;
//int q[N];
//string s;
int a,b,c;
int q[10];
void solve(){
    for(int i=1;i<=3;i++) cin>>q[i];
    int t = max(q[1],max(q[2],q[3]));
    for(int i=1;i<=3;i++) q[i] = t-q[i];
    if(!(q[1]+q[2]+q[3])) return cout<<1<<' '<<1<<' '<<1<<endl,void();
    if(!A&&!B) A++,B++;
    if(!A&&!C) A++,C++;
    if(!B&&!C) C++,B++;
    else cout<<A<<' '<<B<<' '<<C<<endl;
}
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int _=0;cin>>_;
    while(_--) solve();
    return 0;
}