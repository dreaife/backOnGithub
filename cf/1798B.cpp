#include<iostream>
#include<cstring>
#include<algorithm>
#include<set>
#include<vector>
using namespace std;
#define endl '\n'
#define all(v) v.begin(),v.end()
typedef long long ll;
typedef pair<int,int> PII;

//const int N = 2e5+10;
//int a[N];
int m,n;
//string s;
void solve(){
    cin>>m;
    vector<vector<int>> a(m);
    for(int i=0;i<m;i++){
        cin>>n;
        a[i].resize(n);
        for(int j=0;j<n;j++) cin>>a[i][j];
    }
    set<int> p;
    vector<int> ans(m);
    for(int i=m-1;i>=0;i--){
        int t = -1;
        for(auto x:a[i]){
            if(!p.count(x)){
                t = x;
                p.insert(x);
            }
        }
        if(t == -1) return void(cout<<-1<<endl);
        ans[i] = t;
    }
    for(int i=0;i<m;i++) cout<<ans[i]<<' ';
    cout<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int _;cin>>_;
    while(_--) solve();
    return 0;
}