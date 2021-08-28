#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

const int N=5010;
int n,k;
int q[N];
int f[N][N];

int main(){
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        cin>>q[i];
    sort(q+1,q+n+1);
    for(int i=1,j=1;i<=n;i++){
        while(q[i]-q[j]>5) j++;
        for(int n=1;n<=k;n++)
            f[i][n]=max(f[i-1][n],f[j-1][n-1]+i-j+1);
    }
    cout<<f[n][k]<<endl;
    return 0;
}