#include <iostream>
#include <cstring>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
const int N=1e5+10;
class A{
    public:
        int x,y,z;
};
vector<A> w(N);
int v[N];
void qs(int l,int r){
    if(l>=r) return ;
    int i=l-1,j=r+1,x=w[l+r>>1].z;
    while(i<j){
        do i++;while(w[i].z<x);
        do j--;while(w[j].z>x);
        if(i<j){
            swap(w[i].x,w[j].x);swap(w[i].y,w[j].y);swap(w[i].z,w[j].z);
        }
    }
    qs(l,j);
    qs(j+1,r);
}
int main() {
    ll ans=0;
    int n,m,k;cin>>n>>m;
    for(int i=0;i<m;i++)
        cin>>w[i].x>>w[i].y>>w[i].z;
    cin>>k;int x=w[k].x,y=w[k].y,z=w[k].z;
    qs(0,n-1);
    for(int i=0;i<m;i++){
        if(v[w[i].x]&&v[w[i].y]) continue;
        ans+=w[i].z;
        v[w[i].x]++;v[w[i].y]++;
    }
    for(int i=0;i<m;i++)
        if(w[i].x==x&&w[i].y==y&&w[i].z==z){
            k=i;break;
        }
    ll temp=0;temp+=z;w[k].z=0;
    memset(v,0,N);
    v[w[k].x]++;v[w[k].y]++;
    qs(0,n-1);
    for(int i=0;i<m;i++){
        if(v[w[i].x]&&v[w[i].y]) continue;
        temp+=w[i].z;
        v[w[i].x]++;v[w[i].y]++;
    }
    cout<<min(ans+z,temp)<<endl;
    return 0;
}