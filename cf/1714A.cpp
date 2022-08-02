#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
#define endl '\n'
#define all(v) v.begin(),v.end()
typedef long long ll;
typedef pair<int,int> PII;

//const int N = 2e5+10;
PII a[50],sleep;
int n;
//string s;
bool check(PII t1,PII t2){
    if(t1.first==t2.first) return t1.second<t2.second;
    else return t1.first<t2.first;
}
void solve(){
    cin>>n>>sleep.first>>sleep.second;
    for(int i=0;i<n;i++) cin>>a[i].first>>a[i].second;
    sort(a,a+n,check);
    for(int i=0;i<n;i++) if(!check(a[i],sleep)){
        int ans1 = - sleep.first + a[i].first,
            ans2 = - sleep.second + a[i].second;
            if(ans2<0) ans1--,ans2+=60;
        // cout<<1<<endl;
        return void(cout<<ans1<<' '<<ans2<<endl);
    }
    int ans1 = 24 - (sleep.first - a[0].first),
        ans2 = 0 - (sleep.second - a[0].second);
    if(ans2<0) ans1--,ans2+=60;
    cout<<ans1<<' '<<ans2<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int _;cin>>_;
    while(_--) solve();
    return 0;
}