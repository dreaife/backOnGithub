#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N=1010;
int q[N];
int main(){
    int t=0;cin>>t;
    while(t--){
        int n=0;cin>>n;
        for(int i=0;i<n;i++) cin>>q[i];
        sort(q,q+n);
        if(q[0]<0)
            cout<<"NO"<<endl;
        else{
            cout<<"YES"<<endl;
            int k=q[n-1]+1;cout<<k<<endl;
            for(int i=0;i<=q[n-1];i++) cout<<i<<' ';
            cout<<endl;
        }
    }
    return 0;
}