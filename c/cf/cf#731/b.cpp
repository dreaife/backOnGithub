#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
string s;
void solve(){
    cin>>s;s=' '+s;
    int pos=0;
    for(int i=1;i<s.length();i++) if(s[i]=='a') {pos=i;break;}
    for(int i=pos,j=pos,k=1;k<s.length();k++){
        if(s[i]!=(char)(97+k-1)){
            if(s[j+1]==(char)(97+k-1)) ++j;
            else if(s[i-1]==(char)(97+k-1)) --i;
            else {cout<<"NO"<<endl;return;}
        }
    }
    cout<<"YES"<<endl;
}
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int _=0;cin>>_;
    while(_--) solve();
    return 0;
}