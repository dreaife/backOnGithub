#include<iostream>
#include<cmath>
using namespace std;
int main(){
    int a,b,ans;
    cin>>a>>b;
    for(int i=min(a,b);i>=1;i--) if(a%i==0&&b%i==0)
        {ans = i;break;}
    cout<<"两数 最大公约数是"<<ans<<endl;
    for(int i=max(a,b);i<=a*b;i++) if(i%a==0&&i%b==0)
        {ans = i;break;}
    cout<<"两数 最大公约数是"<<ans<<endl;
    return 0;
}