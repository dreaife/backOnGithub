#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
#define endl '\n'
#define all(v) v.begin(),v.end()
typedef long long ll;
typedef pair<int,int> PII;

const int N = 2e5+10;
int a[N];
int n,m1,m2;
//string s;
void solve(){
    cin>>n;m1 = m2 = 0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        int t = m1;
        if(a[i] >= m1) m1 = a[i],m2 = t;
        else m2 = max(m2,a[i]);
    }
    for(int i=0;i<n;i++)
        if(a[i]==m1) cout<<a[i]-m2<<' ';
        else cout<<a[i]-m1<<' ';
    cout<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int _;cin>>_;
    while(_--) solve();
    return 0;
}