#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
#define endl '\n'
#define all(v) v.begin(),v.end()
typedef long long ll;
typedef pair<int,int> PII;

vector<int> a;
map<int,int> pos;
int n,ans;
int gcd(int a,int b){
    if(a%b) return gcd(b,a%b);
    else return b;
}
//string s;
void solve(){
    cin>>n;ans=-1;
    a.clear();pos.clear();
    for(int i=1,tp;i<=n;i++){
        cin>>tp;
        a.push_back(tp);
        pos[tp] = i;
    }sort(a.begin(),a.end());
    a.erase(unique(a.begin(),a.end()),a.end());
    n = a.size();
    for(int i=0;i<n;i++) for(int j=i;j<n;j++)
        if(gcd(a[i],a[j])==1) ans = max(ans,pos[a[i]] + pos[a[j]]);
    cout<<ans<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int _;cin>>_;
    while(_--) solve();
    return 0;
}