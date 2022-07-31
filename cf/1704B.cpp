#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
#define endl '\n'
#define all(v) v.begin(),v.end()
typedef long long ll;
typedef pair<int,int> PII;

//const int N = 2e5+10;
//int a[N];
int n,x,ans;
//string s;
void solve(){
    cin>>n>>x;ans = 0;
    int l=-2e9,r=-2e9;
    for(int i=0,t;i<n;i++){
        cin>>t;
        int ml=t-x,mr=t+x;
        if(ml>r || mr<l){
            if(l!=-2e9)ans ++;
            l = ml;r = mr;
        }else{
            l = max(l,ml);
            r = min(r,mr);
        }
    }cout<<ans<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int _;cin>>_;
    while(_--) solve();
    return 0;
}