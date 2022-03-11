#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
//const int N = 1e5+10;
//int a[N];
//int n;
//string s;
int l,r,a;
int ans;
void solve(){
    cin>>l>>r>>a;ans = 0;
    int nl = max(r/a*a,l+1);
    ans = max((nl-1)/a+(nl-1)%a,r/a+r%a);
    cout<<ans<<endl;
}
// x/a + x mod a
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int _;cin>>_;
    while(_--) solve();
    return 0;
}