#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
string s;
int n,a,b;
void solve(){
    cin>>n>>a>>b;
    cin>>s;
    if(b>=0) cout<<n*a+n*b<<endl;
    else{
        int p0=0,p1=0;
        for(int i=0;i<n;){
            while(s[i]==s[++i]);
            if(s[i-1]=='0') p0++;
            else if(s[i-1]=='1') p1++;
        }
        cout<<n*a+min(p0+1,p1+1)*b<<endl;
    }
}
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int _=0;cin>>_;
    while(_--) solve();
    return 0;
}