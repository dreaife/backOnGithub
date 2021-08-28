#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b){
    int temp=1;
    for(int i=1;i<=min(a,b);i++){
        if(a%i==0&&b%i==0) temp=i;
    }
    return temp;
}
int main(){
    int t=0;
    cin>>t;
    while(t--){
        int k=0;
        cin>>k;
        int temp=0;
        temp=gcd(k,100-k);
        int n=100/temp;
        cout<<n;
    }
    system("pause");
    return 0;
}
