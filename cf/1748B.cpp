#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
#define endl '\n'
#define all(v) v.begin(),v.end()
typedef long long ll;
typedef pair<int,int> PII;

const int N = 1e5+10;
int a[N],cnt[20];
int n,ans;
//string s;
void solve(){
    cin>>n;char t = ' ';ans=0;
    for(int i=0;i<n;i++){
        cin>>t;a[i] = t-'0';
    }
    for(int i=0;i<n;i++){
        for(int k=0;k<10;k++) cnt[k]=0;
        for(int j=i;j<min(i+100,n);j++){
            cnt[a[j]]++;
            int len=0,top=0;
            for(int k=0;k<10;k++) if(cnt[k]){
                len++;
                top = max(top,cnt[k]);
            }
            ans += top<=len;
        }
    }cout<<ans<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int _;cin>>_;
    while(_--) solve();
    return 0;
}