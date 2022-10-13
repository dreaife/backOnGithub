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
//int n;
string a,b;
void solve(){
    cin>>a>>b;
    // cout<<a.back()<<' '<<b.back()<<endl;
    if(a==b) return void(cout<<"="<<endl);
    if(a.back() < b.back()) return void(cout<<">"<<endl);
    else if(a.back() > b.back()) return void(cout<<"<"<<endl);
    if (a.back()=='S') cout<<(a.length()<b.length()?">":"<")<<endl;
    else cout<<(a.length()>b.length()?">":"<")<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int _;cin>>_;
    while(_--) solve();
    return 0;
}