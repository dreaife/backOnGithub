#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
int h,w;
//const int N=1e5+10;
//int q[N];
//string s;
void solve(){
    cin>>h>>w;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(i&&i!=h-1){
                if(!(i%2)&&(j==0||j==w-1))
                    if(i==h-2) cout<<0;
                    else cout<<1;
                else cout<<0;
            }else
                if(j%2) cout<<0;
                else cout<<1;
        }
        cout<<endl;
    }
    cout<<endl;
}
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int _=0;cin>>_;
    while(_--) solve();
    return 0;
}