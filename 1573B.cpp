#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
const int N=1e5+10;
int a[N],b[N],n,ans;
//string s;
void solve(){
    cin>>n;ans=n+10;
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];
    int key = n*2;
    for(int i=0;i<n;i++) if(a[i]<b[0]){
        key = i;break;
    }
    for(int i=0;i<n;i++) if(a[0]<b[i]){
        key = min(key,i);break;
    }
    cout<<key<<endl;
}
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int _=0;cin>>_;
    while(_--) solve();
    return 0;
}