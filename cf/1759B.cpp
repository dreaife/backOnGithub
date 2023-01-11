#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
#define endl '\n'
#define all(v) v.begin(),v.end()
typedef long long ll;
typedef pair<int,int> PII;

//const int N = 2e5+10;
// int a[100];
int m,s;
//string s;
void solve(){
    cin>>m>>s;int tp = 0;
    for(int i=0,t;i<m;i++) cin>>t,s += t,tp = max(tp,t);
    for(int i=1;i<500;i++) if(i*(i+1)/2 == s && i >= tp)
        return void(cout<<"YES"<<endl);
    cout<<"NO"<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int _;cin>>_;
    while(_--) solve();
    return 0;
}