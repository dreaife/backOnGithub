#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N = 2e5+10;
//int a[N];
int n;
char s[N];
void solve(){
    cin>>s;n = strlen(s);
    if(s[0]=='B'||s[n-1]=='A') return void(cout<<"NO"<<endl);
    int c1 =0,c2 = 0;
    for(int i=0;i<n;){
        while(s[i]=='A') i++,c1++;
        while(s[i]=='B'&&i<n) i++,c2++;
        if(c1<c2) return void(cout<<"NO"<<endl);
    }cout<<"YES"<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int _;cin>>_;
    while(_--) solve();
    return 0;
}