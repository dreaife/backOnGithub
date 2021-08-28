#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
//const int N=1e5+10;
//int q[N];
//string s;
int min(int a,int b,int c,int d){
    return min(a,min(b,min(c,d)));
}
void solve(){
    int n=0;cin>>n;
    int minN=0,maxN=0,ans=0;
    for(int i=1;i<=n;i++){
        int temp=0;
        cin>>temp;
        if(temp==1) minN=i;
        if(temp==n) maxN=i;
    }
    ans=min(max(minN,maxN),max(n-maxN+1,n-minN+1),n-minN+maxN+1,n-maxN+minN+1);
    cout<<ans<<endl;
}
int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int _=0;cin>>_;
    while(_--) solve();
    return 0;
}