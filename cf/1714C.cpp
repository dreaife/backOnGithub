#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
#define endl '\n'
#define all(v) v.begin(),v.end()
typedef long long ll;
typedef pair<int,int> PII;

//const int N = 2e5+10;
int n,tot,cnt[20]={1,2,3,4,5,6,7,8,9};
//string s;
void solve(){
    cin>>n;string ans;
    for(int i=8;~i&&n;i--){
        if(cnt[i]>n) continue;
        char t = '0'+cnt[i];
        ans = t + ans;
        n -= cnt[i];
    }cout<<ans<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int _;cin>>_;
    while(_--) solve();
    return 0;
}