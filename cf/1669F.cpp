#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N = 2e5+10;
int a[N];
int n,ans;
//string s;
void solve(){
    cin>>n;ans = 0;int sl,sr;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1,j=n;i<=j;){
        while(sl<sr||!sl) i++,sl+=a[i];
        if(sl==sr) ans = max(ans,i+n-j+1);
        while(sr<sl||!sr) j--,sr+=a[j];
        if(sl==sr) ans = max(ans,i+n-j+1);
    }cout<<ans<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int _;cin>>_;
    while(_--) solve();
    return 0;
}