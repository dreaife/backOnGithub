#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
int nj,no;
//const int N=1e5+10;
//int q[N];
//string s;
void solve(){
    int n=0;cin>>n;
    nj=0;no=0;
    for(int i=0;i<2*n;i++){
        int t=0;cin>>t;
        if(t%2) nj++;
        else no++;
    }
    if(nj==no) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}
int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int _=0;cin>>_;
    while(_--) solve();
    return 0;
}