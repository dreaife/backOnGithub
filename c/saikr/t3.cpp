#include <iostream>
#include <cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N=1e6+10;
int q[N];
int main() {
    int n=0,k=1,m=0;cin>>n;
    string s;cin>>s;
    for(int i=0,j=-1;i<n;i++){
        while(s[i+1]==s[i]) i++;
        q[k++]=i-j;
        j=i;
    }
    int ans=0;
    for(int i=0;i<=k;i++)
        ans=max(ans,q[i-1]+q[i+1]);
    cout<<ans<<endl;
    return 0;
}