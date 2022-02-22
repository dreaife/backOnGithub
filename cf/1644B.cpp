#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
//const int N = 1e5+10;
//int a[N];
int n;
//string s;
void solve(){
    cin>>n;
    for(int i=0,p=0;i<n;i++){
        for(int j=n;j>=1;j--){
            if(p==j+i-n) cout<<1<<' ';
            if(j!=1) cout<<j<<' ';
        }cout<<endl;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int _;cin>>_;
    while(_--) solve();
    return 0;
}