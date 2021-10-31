#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
typedef long long ll;
const int N = 2e5+10;
int a[N],b[N],c;
int n,d,m;
//string s;
void get(int k){
    queue<int> cost;
    for(int i=n-1,p=0;i>=0;i--){
        if(a[i+1]<=m) cost.push(a[i+1]);
        if(a[i]>m){
            
            p++;
        }
    }
}
void solve(){
    cin >> n>>d>>m;c=0;int k=0;memset(a,0,4*n);
    for(int i=0;i<n;i++) {cin>>a[i];if(a[i]>m) k++;}get(k);k=0;
    for(int i=1;i<=d;i++) {if(a[i]<=m) c+=a[i];if(a[i]>m) k++;}
    ll res = 0;
    for(int i=0,p=0;i<n;i++){
        int t=c;
        for(int j=0;j<k;j++) t+=b[p+j];
        if(a[i] <= m) res+=a[i];
        if(a[i]>m) {p++;if(a[i]>t) res+=a[i];i+=d;}
        if(a[i+1]<=m) c -= a[i+1];
        if(a[i+d+1]<=m) c += a[i+d+1];
        if(a[i+d+1] > m) k++;
        if(a[i+1]>m) k--;
    }cout<<res<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    solve();
    return 0;
}