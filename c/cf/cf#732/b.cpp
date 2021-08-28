#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
const int N = 1e5+10;
int n,m;
int a[26][N],b[26][N];
void solve(){
    string s,c;
    cin>>n>>m;
    memset(a,0,sizeof(a));memset(b,0,sizeof(b));
    for(int i=0;i<n;i++){
        cin>>c;
        for(int j=0;j<m;j++){
            char t=c[j];a[t-'a'][j]++;
        }
    }
    for(int i=0;i<n-1;i++){
        cin>>c;
        for(int j=0;j<m;j++){
            char t=c[j];b[t-'a'][j]++;
        }
    }
    for(int i=0;i<m;i++)
        for(int j=0;j<26;j++)
            if(a[j][i]-b[j][i]){
                s+=(char)(97+j);break;
            }
    cout<<s<<endl;
}
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int _=0;cin>>_;
    while(_--) solve();
    return 0;
}