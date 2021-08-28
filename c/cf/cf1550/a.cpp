#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
int s,ans,su;
void solve(){
    ans=0,su=0;
    cin>>s;
    for(int i=1;;i+=2){
        su+=i;ans++;
        if(su>=s){cout<<ans<<endl;break;}
    }
}
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int _=0;cin>>_;
    while(_--) solve();
    return 0;
}