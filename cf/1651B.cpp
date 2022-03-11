#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
//const int N = 1e5+10;
//int a[N];
//int n;
//string s;
int n,N;
void solve(){
    cin>>n;
    if(n>N) return void(cout<<"NO"<<endl);
    cout<<"YES"<<endl;
    for(int i=1,j=1;i<=n;i++)
        cout<<j<<' ',j*=3;cout<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);N=0;
    for(int i=1;i<=1e9;i+=2*i) N++;
    int _;cin>>_;
    while(_--) solve();
    return 0;
}