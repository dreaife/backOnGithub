#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
const int N = 1e6+10;
int n,a,b,c;
vector<int> ans;
string s;
void solve(){
    cin>>n>>s;
    a=0;b=0;c=0;ans.clear();
    for(int i=0;i<n;i++){
        if(s[i]!='a') continue;
        if(s.substr(i,2)=="aa") ans.push_back(2);
        if(s.substr(i,3)=="aba"||s.substr(i,3)=="aca") ans.push_back(3);
        if(s.substr(i,4)=="abca"||s.substr(i,4)=="acba") ans.push_back(4);
        if(s.substr(i,7)=="abbacca"||s.substr(i,7)=="accabba") ans.push_back(7);
    }if(ans.empty()) cout<<-1<<endl;
    else cout<<*min_element(ans.begin(),ans.end())<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int _;cin>>_;
    while(_--) solve();
    return 0;
}