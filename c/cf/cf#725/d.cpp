#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
typedef long long ll;
int calc(int a){
    int n=0;
    for(int i=2;i<=sqrt(a);i++){
        while(a%i==0) a/=i,n++;
        if(a==1) break;
    }
    return n;
}
void solve(){
    int a,b,k;cin>>a>>b>>k;
    int na=calc(a),nb=calc(b);
    if(a==b||(na+nb<k)&&k>=2||k==1&&(max(a,b)%min(a,b))) cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
    
}
int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int _=0;cin>>_;
    while(_--) solve();
    return 0;
}