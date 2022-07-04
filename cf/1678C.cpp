#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N = 5010;

int ba[N],a[N];
int n;
//string s;
void solve(){
    cin>>n;memset(ba,0,sizeof ba);ll ans = 0;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=n;i>0;i++){
        for(int j=i+1;j<=n;j++) if(a[j]<a[i])
            ba[i]++;
    }for(int i=1;i<=n;i++) ba[i] += ba[i-1];
    for(int i=1;i<=n;i++){
        for(int j=1;j<i;j++){
            if(a[j]>a[i]) ba[i]--;
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int _;cin>>_;
    while(_--) solve();
    return 0;
}