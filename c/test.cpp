#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 110;
int q[N];
int ans=0;

int main()
{
    int T;cin>>T;
    while(T--){
        int n,k=0;cin>>n;
        ans=0;
        memset(q,0,sizeof(q));
        for (int i = 0; i < n; i ++ ){
            int t=0;cin>>t;
            q[t]++;
        }
        for (int i = 0; i < N; i ++ ){
            if(q[i]==1&&k==0) {ans=i;k++;}
            if(q[i]==0&&k==1) {ans+=i;break;}
            if(q[i]==0&&k==0) {ans=2*i;break;}
        }
        cout<<ans<<endl;
    }
    return 0;
}