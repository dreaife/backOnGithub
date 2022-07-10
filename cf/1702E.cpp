#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
typedef pair<int,int> PII;
typedef long long ll;
const int N = 2e5+10;
int a[N],b[N];
int n;
PII np[N];
//string s;
void solve(){
    cin>>n;
    for(int i=0;i<n;i++) cin>>np[i].first>>np[i].second;
    for(int i=0;i<n;i++){
        if(!a[np[i].first] && !a[np[i].second]) a[np[i].first]++,a[np[i].second]++;
        else b[np[i].first]++,b[np[i].second]++;
    }for(int i=0;i<n;i++)
        if(a[i] && b[i]) continue;
        else return void(cout<<"NO"<<endl);
    cout<<"YES"<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int _;cin>>_;
    while(_--) solve();
    return 0;
}