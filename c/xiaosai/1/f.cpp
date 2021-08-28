#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[30];
bool check(ll n){
    for(int i=0;i<18;i++)
        if(a[i])
            if(n%a[i]!=0) return 1;
    return 0;
}
void addA(int i){
    a[i]++;
    if(a[i]>=10) a[i]=0,addA(i+1);
}
int main(){
    int t=0;
    cin>>t;
    while(t--){
        ll n=0,temp;
        cin>>n;temp=n;
        for(int i=0;i<18;i++)
            a[i]=temp%10,temp/=10;
        while(check(n)){
            n++;
            addA(0);
        }
        cout<<n<<endl;
    }
    system("pause");
    return 0;
}