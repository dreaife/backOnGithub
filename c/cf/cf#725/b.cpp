#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
const int N=2e5+10;
int q[N];
//string s;
void solve(){
    int n=0,ans=0;cin>>n;
    ll sum=0;
    for(int i=0;i<n;i++){
        cin>>q[i];
        sum+=q[i];
    }
    if(sum%n){
        cout<<-1<<endl;
        return;
    }
    sort(q,q+n,greater<int>());
    for(int i=0;i<n;i++)
        if(q[i]>sum/n) ans++;
        else break;
    cout<<ans<<endl;
}
int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int _=0;cin>>_;
    while(_--) solve();
    return 0;
}