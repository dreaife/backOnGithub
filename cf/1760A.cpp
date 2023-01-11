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
//string s;
void solve(){
    int a,b,c,s;
    cin>>a>>b>>c;
    s = a+b+c;
    cout<<s- max({a,b,c}) - min({a,b,c})<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int _;cin>>_;
    while(_--) solve();
    return 0;
}