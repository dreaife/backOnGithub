#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
//const int N = 1e5+10;
//int a[N];
//int n;
//string s;
void solve(){
    int n;
    cin>>n;
    cout<<"Division ";
    if(n<=1399) cout<<4<<endl;
    else if(n<=1599) cout<<3<<endl;
    else if(n<=1899) cout<<2<<endl;
    else cout<<1<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int _;cin>>_;
    while(_--) solve();
    return 0;
}