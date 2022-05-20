#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N = 1e5+10;
int a[N];
int n,cnt;
//string s;
void solve(){
    cin>>n;cnt = 0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(!a[i]) cnt++;
    }sort(a,a+n);
    if(cnt) return void(cout<<n-cnt<<endl);
    for(int i=0,j=-1;i<n;i++){
        while(a[i]==a[i+1]&&i<n) i++;
        // cout<<i<<' '<<j<<endl;
        if(i-j>1) return void(cout<<n<<endl);
        j = i;
    }cout<<n+1<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int _;cin>>_;
    while(_--) solve();
    return 0;
}