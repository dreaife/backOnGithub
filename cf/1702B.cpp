#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
//const int N = 1e5+10;
int a[50];
int cnt;
string s;
void solve(){
    cin>>s;cnt = 0;
    for(int i=0;i<s.length();){
        memset(a,0,sizeof a);int p=0;
        for(int j=i;p<3&&j<s.length();j++) if(!a[s[j]-'a'])
            p++,a[s[j]-'a']++;
        while(a[s[i]-'a'])
            i++;
        cnt++;//cout<<i<<' ';
    }cout<<cnt<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int _;cin>>_;
    while(_--) solve();
    return 0;
}