#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
//const int N = 1e5+10;
//int a[N];
int n,a,b;
//string s;
void solve(){
    cin>>n>>a>>b;int k = 0,p=a%(b+1);k += a/(b+1);
    for(int i=1,j=1;i<=a-(a%(b+1) - p);i++){
        // if(i==a){
        //     cout<<"RB";
        //     while(p) cout<<"R",p--;
        //     continue;
        // }
        if(i%k==0 && j<=b)
            if(p) cout<<"RBR",p--,j++;
            else cout<<"RB",j++;
        else cout<<"R";
    }cout<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int _;cin>>_;
    while(_--) solve();
    return 0;
}