#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
typedef long long ll;
//const int N=1e5+10;
//int q[N];
string s;
int na,nb,ng,k;
int a[200],b[200];
int ngp[3][200];
void solve(){
    cin >> s;
    na = 0;nb = 0;ng = 0;k = 0;
    for(int i=0;i<s.length()-1;i++)
        if(s[i]=='a'&&s[i+1]=='b') na++;
        else if (s[i]=='b'&&s[i+1]=='a') nb++;
        if(na == nb) return cout<<s<<endl,void();
        int l = 0,r = s.length()-1;
        if(na > nb){
            if(s[r]=='b') s[r] = 'a';
            else if(s[l] == 'a') s[l] = 'b';
        }else{
            if(s[r]=='a') s[r] = 'b';
            else if(s[l] == 'b') s[l] = 'a';
        }
    cout<<s<<endl;
}
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int _=0;cin>>_;
    while(_--) solve();
    return 0;
}