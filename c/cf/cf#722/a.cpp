#include<iostream>
#include<algorithm>
#include<windows.h>
typedef long long ll;
const int N=110;
int a[N];
using namespace std;
void qs(int b[],int l,int r){
    if(l>=r) return ;
    int i=l-1,j=r+1,x=b[l+r>>1];
    while(i<j){
        do i++;while(b[i]<x);
        do j--;while(b[j]>x);
        if(i<j)
            swap(b[i],b[j]);
    }
    qs(b,l,j);
    qs(b,j+1,r);
}
int main(){
    int t=0,n=0;
    cin>>t;
    while(t--){
        cin>>n;int minA=110,ans=0;
        for(int i=0;i<n;i++) cin>>a[i],minA=min(minA,a[i]);
        qs(a,0,n-1);
        for(int i=0;i<n;i++){
            if(a[i]>minA) break;
            ans++;
        }
        cout<<n-ans<<endl;
    }
    system("pause");
    return 0;
}