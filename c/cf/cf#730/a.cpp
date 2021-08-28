#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
ll a,b;
//const int N=1e5+10;
//int q[N];
//string s;
void solve(){
    cin>>a>>b;
    if(b==a) cout<<0<<' '<<0<<endl;
    else if(a==0||b==0) cout<<max(a,b)<<' '<<0<<endl;
    else{
        cout<<abs(b-a)<<' '<<min(a%abs(b-a),abs(b-a)-a%abs(b-a))<<endl;
    }
    //min()
}
int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int _=0;cin>>_;
    while(_--) solve();
    return 0;
}