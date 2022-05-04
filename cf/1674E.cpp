#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N = 2e5+10;
class PP{
    public:int idx,da;
};
PP a[N],b[N];
int n;
//string s;
int calc(int p){
    return 0;
}
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i].da,a[i].idx=i,b[i]=a[i];
    sort(b+1,b+n+1,[](PP a,PP b){return a.da<b.da;});
    for(int i=1;i<=n;i++) cout<<b[i].da<<' '<<b[i].idx<<endl;
    ll ans = 0;
    if(abs(b[1].idx-b[2].idx));
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int _=1;
    while(_--) solve();
    return 0;
}