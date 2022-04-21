#include<iostream>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;
typedef long long ll;
map<int,int> a;
const int N = 2e5+10;
int n;
//string s;
void solve(){
    a.clear();
    cin>>n;
    for(int i=0,t;i<n;i++) cin>>t,a[t]++;
    for(auto i:a) if(i.second >= 3)
        return void(cout<<i.first<<endl);
    cout<<-1<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int _;cin>>_;
    while(_--) solve();
    return 0;
}