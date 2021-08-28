#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
//const int N=1e5+10;
//int q[N];
//string s;
void solve(){
    int n=0;cin>>n;
    if(!(n%2)){
        for(int i=1;i<=n;i+=2)
            cout<<i+1<<' '<<i<<' ';
        cout<<endl;
    }else{
        for(int i=1;i<=n;i+=2){
            if(i==n-2){
                cout<<n<<' '<<n-2<<' '<<n-1;
                break;
            }else{
                cout<<i+1<<' '<<i<<' ';
            }
        }cout<<endl;
    }
}
int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int _=0;cin>>_;
    while(_--) solve();
    return 0;
}