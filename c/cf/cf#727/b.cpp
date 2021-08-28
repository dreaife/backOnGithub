#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
typedef long long ll;
const int N=1e5+10;
//string s;
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,q;
    string s;
    int a[N][30];
    cin>>n>>q;
    cin>>s;
    for(int i=1;i<=n;i++){
        for(int j=0;j<26;j++) a[i][j]=a[i-1][j];
        a[i][s[i-1]-'a']++;
    }
    while(q--){
        int l,r,ans=0;
        cin>>l>>r;
        for(int i=0;i<26;i++)
            ans+=(a[r][i]-a[l-1][i])*(i+1);
        cout<<ans<<endl;
    }
    return 0;
}