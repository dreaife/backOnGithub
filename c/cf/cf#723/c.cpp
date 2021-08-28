#include<iostream>
#include<cstring>
#include<algorithm>
#include<windows.h>
#include<queue>
typedef long long ll;
using namespace std;
const int N=200010;
ll p[N];
priority_queue<int,vector<int>,greater<int> > q;
void tx(int n){
    int res=0;ll ans=0;
    for(int i=1;i<=n;i++){
        if(ans+p[i]<0){
            if(q.empty()||p[i]<=q.top())
                continue;
            else{
                ans=ans-q.top()+p[i];
                q.pop();
                q.push(p[i]);
            }
        }else{
            res++;
            ans+=p[i];
            if(p[i]<0){
                q.push(p[i]);
            }
        }
    }
    cout<<res<<endl;
}
int main(){
    int n=0;cin>>n;
    for(int i=1;i<=n;i++) cin>>p[i];
    tx(n);
    system("pause");
    return 0;
}