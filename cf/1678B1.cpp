#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
vector<int> a;
int n;
string s;
void solve(){
    cin>>n>>s;ll ans = 0;a.clear();
    for(int i=0,j=-1;i<n;i++){
        while(s[i]==s[i+1]&&i<n) i++;
        a.push_back(i-j);j = i;
    }for(int i=0,p=0;i<a.size();i++){
        // cout<<a[i]<<' ';
        if((a[i]+p)%2) ans ++,p=1;
        else p = 0;
    }//cout<<endl;
    cout<<ans<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int _;cin>>_;
    while(_--) solve();
    return 0;
}