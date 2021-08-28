#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>

using namespace std;
typedef long long ll;
const int N = 2e5+10;
vector<int> q;
int a,b;
//string s;

void solve(){
    cin>>a>>b;int ma,mi;
    mi=abs(a-b)/2;ma=2*min(a,b)+mi;
    for(int i=mi;i<=ma;i+=2) q.push_back(i);
    if((a+b)%2) cout<<2*q.size()<<endl;
    else cout<<q.size()<<endl;
    for(int i=0;i<q.size();i++){
        cout<<q[i]<<' ';
        if((a+b)%2) cout<<q[i]+1<<' ';
    }cout<<endl;
    q.clear();
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int _;cin>>_;
    while(_--) solve();
    return 0;
}