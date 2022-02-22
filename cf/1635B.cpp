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
    cin>>n;ans=0;
    for(int i=0;i<n;i++) cin>>a[i];a[n]=0;
    for(int i=1;i<n-1;i++) if(a[i]>a[i-1]&&a[i]>a[i+1])
        a[i+1] = max(a[i],a[i+2]),ans++;
    cout<<ans<<endl;
    for(int i=0;i<n;i++) cout<<a[i]<<' ';cout<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int _;cin>>_;
    while(_--) solve();
    return 0;
}