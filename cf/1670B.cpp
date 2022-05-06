#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N = 1e5+10;
char a[N],c[50];
int n,k;
ll ans;
//string s;
bool check(char t){
    for(int i=0;i<k;i++) if(t==c[i])
        return true;
    return false;
}
void solve(){
    cin>>n>>a>>k;ans = 0;int p = 0;
    for(int i=0;i<k;i++) cin>>c[i];
    for(int i=0,j=0;i<n;i++) if(check(a[i])){
        //cout<<i<<endl;
        ll tmp = i - j;//cout<<tmp<<' '<<ans<<endl;
        if(!p) ans = tmp,p++;
        else ans = max(ans,tmp);
        j = i;
    }cout<<ans<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int _;cin>>_;
    while(_--) solve();
    return 0;
}