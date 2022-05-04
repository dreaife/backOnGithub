#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
//const int N = 1e5+10;
char a[20];
int n,ans;
string s;
void solve(){
    cin>>n;ans=0;
    for(int i=0;i<=n;i++){
        getline(cin,s);//cout<<s<<' '<<i<<endl;
        for(int i=1;i<=4;i++) if(s[i]=='-')
            ans ++;
    }cout<<ans<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int _=1;
    while(_--) solve();
    return 0;
}