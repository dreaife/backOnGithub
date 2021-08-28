#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
const int N=60;
int n,res;
char s[N],tmp[N];
void solve(){
    res=0;
    cin>>n>>s;
    for(int i=0;i<n;i++) tmp[i]=s[i];
    sort(s,s+n);
    for(int i=0;i<n;i++) if(s[i]!=tmp[i])
        res++;
    cout<<res<<endl;
}
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int _=0;cin>>_;
    while(_--) solve();
    return 0;
}