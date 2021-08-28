#include<iostream>
#include<algorithm>
#include<windows.h>
typedef long long ll;
using namespace std;
const int N=60;
ll a[N],b[N],c[N];
int main(){
    int t=0;cin>>t;
    while(t--){
        int n=0;cin>>n;
        for(int i=0;i<2*n;i++) cin>>a[i];
        sort(a,a+2*n);
        for(int i=0;i<n;i++){
            b[i]=a[i];
            c[i]=a[2*n-i-1];
        }
        for(int i=0;i<n;i++){
            a[2*i]=b[i];
            a[2*i+1]=c[i];
        }
        for(int i=0;i<2*n;i++)
            cout<<a[i]<<' ';
        cout<<endl;
    }
    system("pause");
    return 0;
}