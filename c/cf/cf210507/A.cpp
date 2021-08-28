#include<bits/stdc++.h>
using namespace std;
void find_case(){
    int n=0;
    cin>>n;
    vector<unsigned long long> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    int i=0;
    int min=1e9;
    for(int m=0;m<n;m++){
        if(a[m]<min){
            min=a[m];
            i=m;
        }
    }
    cout<<n-1<<endl;
    if(!(n-1)) return;
    for(int j=0;j<n;j++){
        if(j==i) continue;
        unsigned long long temp=(abs(i-j)%2==0)?a[i]:a[i]+1;
        cout<<j+1<<' '<<i+1<<' '<<temp<<' '<<a[i]<<endl;
    }
}
int main(){
    int times=0;
    cin>>times;
    for(int i=0;i<times;i++){
        find_case();
    }
    system("pause");
    return 0;
}