#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
//const int N=1e5+10;
//int q[N];
string s;
int m;
int k;
void solve(){
    cin>>s;k=0;m = 133;
        for(int i=0;i<s.length();i++) if(s[i]<m) m=s[i],k=i;
        cout<<s[k]<<' ';
        for(int i=0;i<s.length();i++) if(i!=k) cout<<s[i];cout<<endl;
}
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int _=0;cin>>_;
    while(_--) solve();
    return 0;
}