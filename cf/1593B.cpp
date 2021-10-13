#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
//const int N=1e5+10;
//int q[N];
string s;
ll a;
void solve(){
    cin>>a;a *= 2;
    s = ' ';
    while(a){
        s += (a%10ll)+'0';
        a /= 10ll;
        cout<<s<<endl;
    }
    int p1=1,p2=1;
    while(s[p1]!='0') p1++;p2=p1+1;
    while(s[p2]!='0'&&s[p2]!='5') p2++;
    //cout<<p1<<' '<<p2<<endl;
    cout<<p2-1<<endl;
}
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int _=0;cin>>_;
    while(_--) solve();
    return 0;
}