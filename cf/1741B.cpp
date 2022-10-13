#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
#define endl '\n'
#define all(v) v.begin(),v.end()
typedef long long ll;
typedef pair<int,int> PII;

//const int N = 2e5+10;
//int a[N];
int n;
//string s;
void solve(){
    cin>>n;
    if(n==3) return void(cout<<"-1"<<endl);
    if(n%2) {
        for(int j=n,i=0;i<n;i++)
            if(i<n/2) cout<<j--<<' ';
            else {j=1;while(i++<n) cout<<j++<<' ';}
    }else {
        for(int i=n;i;i--) cout<<i<<' ';
    }cout<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int _;cin>>_;
    while(_--) solve();
    return 0;
}
//5 4 1 2 3