#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
#define endl '\n'
#define all(v) v.begin(),v.end()
typedef long long ll;
typedef pair<int,int> PII;

const int N = 110;
int a[N],b[N];
int n,m1,m2;
//string s;
void solve(){
    cin>>n;m1 = m2 = 0;
    for(int i=1;i<=n;i++) cin>>a[i];m1 = a[n];
    for(int i=1;i<=n;i++) cin>>b[i];m2 = b[n];
    for(int i=n;i>0;i--){
        if((a[i]<=m1&&b[i]<=m2) || (a[i]<=m2&&b[i]<=m1))
            continue;
        else 
            return void(cout<<"No"<<endl);
    }cout<<"Yes"<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int _;cin>>_;
    while(_--) solve();
    return 0;
}