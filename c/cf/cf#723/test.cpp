#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
typedef long long ll;
const int N=200010;
ll a[N];
priority_queue<int,vector<int>,greater<int>> q;

int main(){
    ll n,ans=0,res=0;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        if(ans+a[i]<0){
            if(q.empty()||q.top()>=a[i]) 
                continue;
            else{
                ans=ans-q.top()+a[i];
                q.pop();
                q.push(a[i]);
            }
        }else{
            res++;
            ans+=a[i];
            if(a[i]<0)
                q.push(a[i]);
        }
    }
    cout<<res<<endl;
    return 0;
}