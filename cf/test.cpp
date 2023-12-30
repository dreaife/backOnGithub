#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
    int f[10010];
    f[0]=1;f[1]=1;
    int n;cin>>n;
    for(int i=2;i<n;i++) f[i]=f[i-2]+f[i-1];
    cout<<f[n-1]<<endl;
    return 0;
}