#include<iostream>
#include<cstring>
#include<algorithm>
#include<windows.h>
typedef long long ll;
using namespace std;
int q[10];
int main(){
    int t=0;cin>>t;
    while(t--){
        for(int i=0;i<4;i++) cin>>q[i];
        int a=max(q[0],q[1]),b=max(q[2],q[3]);
        sort(q,q+4);
        if(a>=q[2]&&b>=q[2]) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    system("pause");
    return 0;
}