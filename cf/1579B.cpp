#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
const int N=100;
struct app{
    int a,p;
    bool operator< (app a){
        if(this->a<a.a) return true;
        else return false;
    }
}a[N];
int n,ans[N][3],res;
//string s;
void solve(){
    cin>>n;res = 0;
    for(int i=0;i<n;i++) cin>>a[i].a,a[i].p=i;
    sort(a,a+n);res = n-1;
    for(int i=0;i<n-1;i++){
        ans[i][0]=i+1;ans[i][1]=a[i].p+1;ans[i][2]=a[i].p-i;
        if(!ans[i][2]) res--;
        for(int j=i;j<a[i].p;j++){
            for(int k=0;k<n;k++) if(a[k].p == j)
                {a[k].p++;break;}
        }a[i].p = i;
    }
    cout<<res<<endl;
    for(int i=0;i<n;i++)
        if(!ans[i][2]) continue;
        else cout<<ans[i][0]<<' '<<ans[i][1]<<' '<<ans[i][2]<<endl;

    for(int i=0;i<n;i++) cout<<a[i].a<<' ';cout<<endl;
    for(int i=0;i<n;i++) cout<<a[i].p<<' ';cout<<endl;
}
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int _=0;cin>>_;
    while(_--) solve();
    return 0;
}