#include<bits/stdc++.h>
using namespace std;
const int N=60;
int q[N];
int w[7]={2,4,8,16,32,64};
bool check(int a,int b){
    if(1.0*max(a,b)/min(a,b)<=2) return 1;
    else return 0;
}
int find(int a,int b){
    int i=0;
    if(a>b) swap(a,b);
    for(i=0;i<6;i++){
        if(check(a*w[i],b)) break;
    }
    return i+1;
}
int main(){
    int t=0;
    cin>>t;
    while(t--){
        int n=0,ans=0;cin>>n;
        for(int i=0;i<n;i++) cin>>q[i];
        for(int i=0;i<n-1;i++){
            if(!check(q[i],q[i+1])){
                ans+=find(q[i],q[i+1]);
            }
        }
        cout<<ans<<endl;
    }
    system("pause");
    return 0;
}