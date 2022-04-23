#include<iostream>
using namespace std;
const int N = 1e5+10;
int n,q,p,ne[N],d[N],a[N];
int fa(int x){
    if(ne[x]==-1) return 1;
    int t = fa(ne[x]);
    d[x] += d[ne[x]];
    return ne[x] = t;
}
int main(){
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>ne[i],d[i]=1;
    }d[p]=0;
    for(int i=1;i<=n;i++) if(ne[i]==-1){
        p = i;break;
    }
    for(int i=1;i<=n;i++) 
        fa(i);
    while(q--){
        int ttt;cin>>ttt;fa(ttt);
        cout<<1+d[ttt]<<endl;
    }
    
    return 0;
}