#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
typedef long long ll;
//const int N=1e5+10;
//int q[N];
string s;
int k,ans,num[50];
bool check(int a,int b){
    int p = 10*a+b;
    for(int i=2;i<=sqrt(p);i++) if(p%i==0)
        return true;
    return false;
}
void solve(){
    cin>>k>>s;ans=0;
    memset(num,0,sizeof num);
    for(int i=0;i<s.length();i++) num[s[i]-'0']++;
    for(int i=1;i<10;i++) if(num[i])
        if(i==1||i==4||i==6||i==8||i==9) {cout<<1<<endl<<i<<endl;return;}
    cout<<2<<endl;
    for(int i=0;i<k;i++)
        for(int j=i+1;j<k;j++) 
            if(check(s[i]-'0',s[j]-'0')) {cout<<s[i]<<s[j]<<endl;return;}
}
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int _=0;cin>>_;
    while(_--) solve();
    return 0;
}