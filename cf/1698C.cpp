#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
//const int N = 1e5+10;
int n0,n1,n2;
int n;
vector<ll> a;
bool check(ll p){
    for(auto i:a) if(i==p)
        return true;
    return false;
}
void solve(){
    cin>>n;n0=n1=n2=0;a.clear();
    for(int i=0;i<n;i++){
        int t;cin>>t;
        if(t){
            if(t>0){
                if(n1++ >= 2) continue;
                a.push_back(t);
            }else{
                if(n2++ >= 2) continue;
                a.push_back(t);
            }
        }else n0++;
    }if(n1>2||n2>2) return void(cout<<"NO"<<endl);
    for(int i=0;i<min(n0,2);i++) a.push_back(0);
    sort(a.begin(),a.end());
    for(int i=0;i<a.size();i++) for(int j=i+1;j<a.size();j++) for(int k=j+1;k<a.size();k++){
        ll t = a[i]+a[j]+a[k];
        if(check(t)==false) return void(cout<<"NO"<<endl);
    }cout<<"YES"<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int _;cin>>_;
    while(_--) solve();
    return 0;
}