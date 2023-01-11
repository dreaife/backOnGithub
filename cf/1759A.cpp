#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
#define endl '\n'
#define all(v) v.begin(),v.end()
typedef long long ll;
typedef pair<int,int> PII;

//const int N = 2e5+10;
//int a[N];
//int n;
string s;
void solve(){
    cin>>s;
    int len = s.length();
    for(int i=0;i<len;i++){
        if(s[i]!='Y' && s[i]!='e' && s[i]!='s')
            return void(cout<<"NO"<<endl);
        if(i+1<len){
            // cout<<1<<' ';
            if(s[i]=='Y') if(s[i+1]!='e')
                return void(cout<<"NO"<<endl);
            if(s[i]=='e') if(s[i+1]!='s')
                return void(cout<<"NO"<<endl);
            if(s[i]=='s') if(s[i+1]!='Y')
                return void(cout<<"NO"<<endl);
        }
    }cout<<"YES"<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int _;cin>>_;
    while(_--) solve();
    return 0;
}