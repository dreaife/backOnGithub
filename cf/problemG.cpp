#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
//const int N = 1e5+10;
//int a[N];
int n;
//string s;
void solve(){
    cin>>n;int x,y;
    for(int i=0;i<n;i++) cin>>x>>y;
    double ans = 1.0 / n;
    printf("%.10lf\n",ans);
}
int main(){
    int _=1;
    while(_--) solve();
    return 0;
}