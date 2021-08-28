#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
int n,a,b;
bool check(int n){
    ll t=1;
    for(int i=0;i<32;i++){
        if(t>n) break;
        if((n-t)%b==0) return true;
        t*=a;
    }
    return false;
}
void solve(){
    n,a,b;
    cin>>n>>a>>b;
    if(n==1||b==1) cout<<"Yes"<<endl;
    else if(a==1)
        if((n-1)%b==0) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    else if(check(n)) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}
int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int _=0;cin>>_;
    while(_--) solve();
    return 0;
}