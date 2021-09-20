#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
//const int N=1e5+10;
int n;
//string s;
void solve(){
    cin>>n;
    for(int i=0;i<n;i++){
        if(i==n-1) {for(int j=0;j<n;j++) cout<<"()";cout<<endl;break;}
        for(int j = 0;j<n-1;j++){
            cout<<"(";
            if(j==i) cout<<"()";
            cout<<")";
        }cout<<endl;
    }
}
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int _=0;cin>>_;
    while(_--) solve();
    return 0;
}