#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
const int N=2e5+10;
int a[N],ap[N],p[N];
bool b[N];
int n,num0,num1,num2;
//string s;
void solve(){
    int k=1;
    num0=0;num1=0;num2=0;
    cin>>n;memset(b,0,4*n);memset(ap,0,4*n);
    for(int i=1;i<=n;i++){cin>>a[i];ap[a[i]]++;}
    for(int i=1;i<=n;i++)
        if(!ap[i]) {num0++;p[k++]=i;}
        else if(ap[i]==1) num1++;
        else num2++;
    cout<<num2+num1<<endl;
    for(int i=1,k=1;i<=n;i++){
        if(ap[a[i]]&&b[a[i]]==false) {cout<<a[i]<<' ';b[a[i]]=true;}
        else cout<<p[k++]<<' ';
    }cout<<endl;
}
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int _=0;cin>>_;
    while(_--) solve();
    return 0;
}