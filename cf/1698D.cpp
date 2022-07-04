#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
int n;
//string s;
void solve(){
    cin>>n;
    int l=1,r=n;
    while(l<r){
        int mid = l + r >> 1;
        cout<<"? "<<l<<' '<<mid<<endl;
        int np=mid-l+1,cnt=0,t;
        for(int i=0;i<np;i++){
            cin>>t;
            if(t>=l && t<= mid) cnt++;
        }if(cnt&1) r=mid;
        else l=mid+1;
    }cout<<"! "<<l<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int _;cin>>_;
    while(_--) solve();
    return 0;
}