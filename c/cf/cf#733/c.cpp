#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
typedef long long ll;
const int N = 1e5+10;
int n,gra1,gra2;
int pos,p2,ans=0;
deque<int> a(N),b(N);
void solve(){
    gra1=0;gra2=0;ans=0;
    cin>>n;
    for(int i=0;i<n;i++) {cin>>a[i];gra1+=a[i];}
    for(int i=0;i<n;i++) {cin>>b[i];gra2+=b[i];}
    sort(a.begin(),a.begin()+n);sort(b.begin(),b.begin()+n);
    for(int i=0;i<n/4;i++) gra1-=a[i];pos=n/4-1;
    for(int i=0;i<n/4;i++) gra2-=b[i];p2=n/4-1;
    while(gra1<gra2){
        a[n+ans]=100;b.push_front(0);
        gra1+=100;gra2+=b[p2+1];
        if((n+ans+1)/4>pos+1){
            gra2-=b[++p2];
            gra1-=a[pos++];
        }
        ans++;
    }
    cout<<ans<<endl;
}
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int _=0;cin>>_;
    while(_--) solve();
    return 0;
}