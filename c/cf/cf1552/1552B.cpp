#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
const int N=50010;
int a[N][10];
int n;
//string s;
bool check(int pos1,int pos2){
    int res=0;
    for(int i=0;i<5;i++) if(a[pos1][i]<a[pos2][i])
        res++;
    return res>=3;
}
void solve(){
    int p=0;
    memset(a,0,sizeof a);
    cin>>n;
    for(int i=0,t;i<n;i++) for(int j=0;j<5;j++) cin>>a[i][j];
    for(int i=0;i<n;i++) if(check(i,p)) p=i;
    for(int i=0;i<n;i++) if(check(i,p)) {cout<<-1<<endl;return;}
    cout<<p+1<<endl;
}
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int _=0;cin>>_;
    while(_--) solve();
    return 0;
}