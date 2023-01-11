#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
#define endl '\n'
#define all(v) v.begin(),v.end()
typedef long long ll;
typedef pair<int,int> PII;

const int N = 2e5+10;
int a[N];
int n,ans;
//string s;
void solve(){
    cin>>n;ans=0;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    n = unique(all(a)) - a.begin();
    for(int i=0;i<n;i++)
        if((i==0||a[i-1]>a[i]) && (i==n-1||a[i]<a[i+1]))
            ans++;
    if(ans == 1) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int _;cin>>_;
    while(_--) solve();
    return 0;
}