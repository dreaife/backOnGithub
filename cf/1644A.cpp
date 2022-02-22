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
    int p1[5],p2[5];
    for(int i=0;i<s.length();i++)
        if(s[i]=='r') p1[0]=i;
        else if(s[i]=='g') p1[1]=i;
        else if(s[i]=='b') p1[2]=i;
        else if(s[i]=='R') p2[0]=i;
        else if(s[i]=='G') p2[1]=i;
        else if(s[i]=='B') p2[2]=i;
    for(int i=0;i<3;i++) if(p1[i]>p2[i])
        {cout<<"NO"<<endl;return;}
    cout<<"YES"<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int _;cin>>_;
    while(_--) solve();
    return 0;
}