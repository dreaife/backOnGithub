#include<iostream>
#include<algorithm>
#include<windows.h>
typedef long long ll;
const int N=1e5+10;
ll q[N];
using namespace std;
int main(){
    int t;cin>>t;
    while(t--){
        ll n,temp,nf=0,mp=1e9+10,kz=0;
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>temp;q[i]=temp;
            if(temp<=0) nf++;
        }
        sort(q,q+n);
        for(int i=1;i<n;i++){
            if(q[i]<=0) mp=min(abs(q[i-1]-q[i]),mp);
            if(q[i]>0){
                if(q[i]<=mp)
                    kz=1;
                else break;
            }
        }
        if(n==1&&!nf) cout<<1<<endl;
        else cout<<nf+kz<<endl;
    }
    system("pause");
    return 0;
}