#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
#define endl '\n'
#define all(v) v.begin(),v.end()
typedef long long ll;
typedef pair<int,int> PII;
#define int ll

//const int N = 2e5+10;
//int a[N];
int m,t,a,b,n;
int hl,hr,tr,tl;
//string s;
void solve(){
    cin>>m;hl = 1;hr = LONG_LONG_MAX;
    while(m--){
        cin>>t;
        if(t == 1){
            cin>>a>>b>>n;
            tr = (a-b)*(n-1) + a;
            tl = n>1?(tr - a+b):0;tl++;
            if(tl<=hr && hl<=tr)
                hl = max(hl,tl),hr = min(hr,tr),cout<<1<<' ';
            else cout<<0<<' ';
        }else{
            cin>>a>>b;
            int t = a-b-b-1;
            int t1 = hl<=a ? 1 : (hl+t) / (a-b),
                t2 = hr<=a ? 1 : (hr+t) / (a-b);
            if(t1 == t2) cout<<t1<<' ';
            else cout<<-1<<' ';
        }
    }cout<<endl;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int _;cin>>_;
    while(_--) solve();
    return 0;
}
// [a*(n-1) - b*(n-2) + 1,a*n - b*(n-1)]
// t+a-b-b-1=(a-b)*n
// t+a-b-b-1=a*(n+1)-b*(n+1)-1=(a-b)*(n+1)-1