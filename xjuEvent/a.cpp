#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N = 1010;
//int a[N];
int n,V,M;
int v[N],m[N],w[N],f[N][N];
// string s;
void solve(){
    cin>>n>>V>>M;
    for(int i=1;i<=n;i++) cin>>v[i]>>m[i]>>w[i];
    for(int i=1;i<=n;i++){
        for(int j=V;j>=v[i];j--){
            for(int k=M;k>=m[i];k--){
                f[j][k] = max(f[j][k],f[j-v[i]][k-m[i]]+w[i]);
            }
        }
    }cout<<f[V][M]<<endl;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int _=1;
    while(_--) solve();
    return 0;
}