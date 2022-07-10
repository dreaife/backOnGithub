#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
typedef long long ll;
int n,q,l,r;
vector<vector<int>> a;
map<int,int> cnt;
//string s;
void solve(){
    cin>>n>>q;
    for(int i=1,j=1,t;i<=n;i++){cin>>t;
        if(cnt.find(t)!=cnt.end()) a[cnt[t]-1].push_back(i);
        else cnt[t]=j++,a.push_back({t,i});
    }while(q--){
        cin>>l>>r;
        if(cnt.find(l)==cnt.end() || cnt.find(r)==cnt.end()) {cout<<"NO"<<endl;continue;}
        int p1=cnt[l]-1,p2=cnt[r]-1;
        // cout<<a[p1][1]<<' '<<a[p2][a[p2].size()-1]<<endl;
        if(a[p1][1]<a[p2][a[p2].size()-1]) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }a.clear();cnt.clear();//cout<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int _;cin>>_;
    while(_--) solve();
    return 0;
}