#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

const int N=110;
char q[N];

int main(){
    int t=0;cin>>t;
    while(t--){
        int n=0,k=0;cin>>n>>k;
        for(int i=1;i<=n;i+=k){
            for(int j=i;j<=min(i+k-1,n);j++)
                q[j]='a'+j%k-1;
        }
        for(int i=1;i<=n;i++)
            cout<<q[i]<<' ';
        cout<<endl;
    }
    return 0;
}