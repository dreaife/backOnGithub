#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
const int N = 1e6+10;
int n,a,b,c;
string s;
void solve(){
    cin>>n>>s;
    a=0;b=0;c=0;
    for(int i=0;i<n;i++){
        if(s[i]!='a') continue;
        if(s.substr(i,2)=="aa") return cout<<2<<endl,void();
        if(s.substr(i,3)=="aba"||s.substr(i,3)=="aca") return cout<<3<<endl,void();
        if(s.substr(i,4)=="abca"||s.substr(i,4)=="acba") return cout<<4<<endl,void();
        if(s.substr(i,7)=="abbacca"||s.substr(i,7)=="accabba") return cout<<7<<endl,void();
    }cout<<-1<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int _;cin>>_;
    while(_--) solve();
    return 0;
}