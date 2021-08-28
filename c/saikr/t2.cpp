#include <iostream>
#include <cstring>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
const int N=2e5+10;
ll q[N];
int main() {
    int n,m,k=0;cin>>n>>m;
    vector<vector<int>> cnt(n);
    ll ans=0;
    while(m--){
        int cho=0;cin>>cho;
        if(cho){
            int x=0;cin>>x;
            ll temp=ans;
            for(auto i=0;i<cnt[x-1].size();i++)
                temp-=q[cnt[x-1][i]];
            cout<<temp<<endl;
        }else{
            ll l,r,z;
            cin>>l>>r>>z;
            ans+=(r-l+1)*z;
            for(int i=l-1;i<r;i++) cnt[i].push_back(k);
            q[k++]=(r-l+1)*z;
        }
    }

    return 0;
}