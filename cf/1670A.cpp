#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N = 1e5+10;
int a[N];
int n,np,nn,p,cp;
//string s;
void solve(){
    cin>>n;np = nn = p = cp = 0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]>0) np ++;
        else if(a[i]<0) nn ++;a[i] = abs(a[i]);
    }for(int i=1;i<=nn;i++) a[i] *= -1;
    for(int i=2;i<=n;i++) if(a[i]<a[i-1])
        return void(cout<<"NO"<<endl);
    cout<<"YES"<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int _;cin>>_;
    while(_--) solve();
    return 0;
}