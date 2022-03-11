#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
//const int N = 1e5+10;
//int a[N];
//int n;
string s;
char c;
void solve(){
    cin>>s>>c;
    for(int i=0;i<s.length();i+=2) if(s[i]==c)
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