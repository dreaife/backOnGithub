#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
//const int N=1e5+10;
int a,b,c,m;
//string s;
void max(){
    int q[10];
    q[0] = a,q[1] = b,q[2] = c;
    sort(q,q+3);
    a = q[0],b = q[1],c = q[2];
}
void solve(){
    cin>>a>>b>>c>>m;max();
    int lb = c-a-b-1,ub = a+b+c-3;
    if(m<=ub&&m>=lb) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int _=0;cin>>_;
    while(_--) solve();
    return 0;
}