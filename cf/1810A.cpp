#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
#define endl '\n'
#define all(v) v.begin(),v.end()
typedef long long ll;
typedef pair<int,int> PII;

const int N = 110;
int a[N];
int n;
//string s;
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) if(a[i] <= i){
        return void(cout<<"YES"<<endl);
    }
    cout<<"NO"<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int _;cin>>_;
    while(_--) solve();
    return 0;
}