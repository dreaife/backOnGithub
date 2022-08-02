#include<iostream>
#include<algorithm>
#include<cstring>
#include<unordered_map>
#include<vector>
using namespace std;
const int N = 4010;
int k,q,n,m,ans;
unordered_map<string,int> cnt;
int main(){
    cin>>k>>n;ans=0;
    string r1[N],r2[N],t;
    unordered_map<string,int> wt;
    for(int i=0;i<n;i++) cin>>r1[i],cnt[r1[i]]=0;cin>>m;
    for(int i=0;i<m;i++) cin>>r2[i],cnt[r2[i]]=0;cin>>q;
    for(int i=0;i<q;i++) cin>>t,wt[t]=0,cnt[t]=1;
    for(int i=0,tp=0;tp<k;i++) if(cnt[r1[i]]==1 && wt[r1[i]]==0){
        wt[r1[i]]++;tp++;
        ans++;
    }
    for(int i=0,tp=0;i<m&&tp<k;i++) if(cnt[r2[i]]==1 && wt[r2[i]]==0){
        wt[r2[i]]++;tp++;
        ans++;
    }
    vector<string> ma;
    for(auto x:wt) if(x.second){
        ma.push_back(x.first);
    }sort(ma.begin(),ma.end());
    cout<<ans<<endl;
    for(int i=0;i<n;i++){
        if(i==n-1) cout<<ma[i];
        else cout<<ma[i]<<endl;
    }
    return 0;
}