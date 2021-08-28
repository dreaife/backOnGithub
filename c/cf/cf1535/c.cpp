#include<iostream>
#include<cstring>
#include<algorithm>
typedef long long ll;
using namespace std;
int main(){
    int t=0;cin>>t;
    while(t--){
        string s;cin>>s;
        ll ans=0;
        int cnt[2]={-1,-1};
        for(int i=0;i<s.size();i++){
            if(s[i]=='1'||s[i]=='0'){
                int x=(i&1)^(s[i]-'0');
                cnt[x]=i;
            }
            ans+=i-min(cnt[0],cnt[1]);
        }
        cout<<ans<<endl;
    }
    return 0;
}