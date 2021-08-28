#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
const int N=60;
int q[N];
//string s;
void solve(){
    int n=0;cin>>n;
    ll sum=0;
    for(int i=0;i<n;i++){
        int t=0;cin>>t;
        sum+=t;
    }
    if(sum<n)
        cout<<1<<endl;
    else
        cout<<sum-n<<endl;
}
int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int _=0;cin>>_;
    while(_--) solve();
    return 0;
}