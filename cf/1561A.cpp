#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;
typedef long long ll;
const int N = 1e4+10;
int a[N];
int n;
//string s;

bool check(){
    for(int i=1;i<n;i++) if(a[i]>a[i+1])
        return false;
    return true;
}

void solve(){
    cin>>n;int p=0;
    for(int i=1;i<=n;i++) cin>>a[i];
    while(!check()){
        for(int i=1+p%2;i<n;i+=2) if(a[i]>a[i+1]) swap(a[i],a[i+1]);
        p++;
    }cout<<p<<endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int _;cin>>_;
    while(_--) solve();
    return 0;
}