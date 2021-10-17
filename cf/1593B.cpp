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
    int p0=1,p2=1,p5=1,p7=1;
    while(s[p0]!='0') p0++;
    while(s[p5]!='5') p5++;p7 = p5;
    while(s[p7]!='7') p7++;

    cout<<p2-1<<endl;
}
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int _=0;cin>>_;
    while(_--) solve();
    return 0;
}