#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
//const int N = 1e5+10;
//int a[N];
//int n;
string s;
void solve(){
    cin>>s;
    s[0]=s[0]-1;
    if(s[0]=='0'){
        for(int i=0;i<s.length();i++) if(s[i]!='0')
            return void(cout<<s.substr(i,s.length()-i)<<endl);
        cout<<0<<endl;
    }else cout<<s<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int _;cin>>_;
    while(_--) solve();
    return 0;
}