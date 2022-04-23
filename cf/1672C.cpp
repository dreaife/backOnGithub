#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N = 2e5+10;
int a[N];
int n;
//string s;
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1,j = 0;i<=n;i++){
        while(a[i]==a[i+1]) i++;
        if(i-j>2)
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int _;cin>>_;
    while(_--) solve();
    return 0;
}