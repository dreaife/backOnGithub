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
int n;
//string s;
void solve(){
    cin>>n;
    if(n==1) return void (cout<<1<<endl);
    if(n==2) return void (cout<<2<<' '<<1<<endl);
    if(n==3) return void (cout<<"2 3 1"<<endl);
    for(int i=1;i<=n;i+=2) {
        if(n%2){
            if(i==1) {cout<<2<<' '<<n<<' ';continue;}
            if(i==n) return void(cout<<1<<endl);
        }cout<<i+1<<' '<<i<<' ';
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int _;cin>>_;
    while(_--) solve();
    return 0;
}