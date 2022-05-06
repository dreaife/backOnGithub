#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int N = 1e5+10;
int a[N],b[N],d[N];
int n;
//string s;
void solve(){
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];
    for(int i=0;i<n;i++) cin>>d[i];
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int _;cin>>_;
    while(_--) solve();
    return 0;
}