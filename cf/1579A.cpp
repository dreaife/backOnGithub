#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
//const int N=1e5+10;
int a,b,c;
string s;
void solve(){
    cin>>s;a=0;b=0;c=0;
    for(int i=0;i<s.length();i++){
        if(s[i] == 'A') a++;
        else if(s[i] == 'B') b++;
        else c++;
    }if(a+c==b) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int _=0;cin>>_;
    while(_--) solve();
    return 0;
}