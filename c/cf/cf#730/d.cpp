#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
//const int N=1e5+10;
//int q[N];
//string s;
void solve(){
    int n,k;cin>>n>>k;
    int cp=0;
    cout<<0<<endl;
    cin>>cp;
    if(cp) return;
    for(int i=1;i<n;i++){
        cout<<(i^(i-1))<<endl;
        cin>>cp;
        if(cp) return;
    }
}
int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int _=0;cin>>_;
    while(_--) solve();
    return 0;
}