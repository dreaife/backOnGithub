#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
#define endl '\n'
#define all(v) v.begin(),v.end()
typedef long long ll;
typedef pair<int,int> PII;
#define int ll

const int N = 3e5+10;
int a[N],b[N],c[N];
int n,m,ans,ansN,num1,num2;
//string s;
void solve(){
    cin>>n>>m;ans=ansN=num1=num2=0;
    bool flag=false;
    memset(a,0,sizeof a);
    for(int i=0;i<m;i++) cin>>a[i];
    for(int j=1;j<n;j++){
        num1 = num2 = 0;
        for(int i=0,lot=0;i<m;i++){
            cin>>b[i];
            if(b[i]+lot<a[i]) num1 += a[i]-b[i]-lot,lot-=a[i]-b[i];
            else num2 += b[i]+lot-a[i],lot+=b[i]-a[i];
        }//cout<<num1<<' '<<num2<<endl;
        if(num1 > num2){
            ans = j;
            ansN = num1-num2;
            // cout<<endl;
        }else if(num1 < num2){
            num1 = num2 = 0;
            for(int i=0,lot=0;i<m;i++){
                swap(a[i],b[i]);
                if(b[i]+lot<a[i]) num1 += a[i]-b[i]-lot,lot-=a[i]-b[i];
                else num2 += b[i]+lot-a[i],lot+=b[i]-a[i];
                // cout<<num1<<' '<<num2<<' '<<lot<<endl;
            }ans = 0;ansN = num1-num2;
        }
    }cout<<++ans<<' '<<ansN<<endl;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int _;cin>>_;
    while(_--) solve();
    return 0;
}