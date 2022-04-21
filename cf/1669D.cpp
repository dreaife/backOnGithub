#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N = 1e5+10;
//int a[N];
int n;
char a[N];
void solve(){
    cin>>n>>a+1;a[0]=a[n+1]='W';
    for(int i=0,j=0;i<=n;i++){
        int cnt1=0,cnt2=0;
        while(a[i]=='W') i++;j = i;
        while(a[i]!='W'&&i<=n){
            if(a[i]=='R') cnt1++;
            else if(a[i]=='B') cnt2++;
            i++;
        }i--;
        if((!cnt1||!cnt2) && cnt1+cnt2) return void(cout<<"NO"<<endl);
    }cout<<"YES"<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int _;cin>>_;
    while(_--) solve();
    return 0;
}