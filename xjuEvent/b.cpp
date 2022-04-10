#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
const int N = 1e5+10;
#define int ll
int n,p1,p2,d=0;
vector<int> a;
//string s;
void solve(){
    cin>>n;p1 = p2 = 0;
    for(int i=1,p;i<=n;i++) cin>>p,a.push_back(p);
    sort(a.begin(),a.end());int t=a.back(),p=0;
    while(!a.empty()){
        int t = a.back();p ^= t;
        /*p1 ^= a.back();*/a.pop_back();
        // if(!a.empty()) {t = a.back();p ^= t;p2 ^= a.back();a.pop_back();}
    }
    // if(p1>p2) cout<<"WON"<<endl;
    // else if(p1==p2) cout<<"DRAW"<<endl;
    // else cout<<"LOSE"<<endl;
    for(int i=0;1<<i<t;i++){
        if(t&1<<i==0) d += 1<<i;
    }if(!p) cout<<"DRAW"<<endl;
    else{
        if(d>p) cout<<"WIN"<<endl;
        else cout<<"LOSE"<<endl;
    }
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    solve();
    return 0;
}