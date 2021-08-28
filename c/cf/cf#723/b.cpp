#include<iostream>
#include<algorithm>
#include<windows.h>
typedef long long ll;
using namespace std;
ll q[2]={111,11};
int main(){
    int t=0;cin>>t;
    while(t--){
        ll temp=0;cin>>temp;
        for(int i=0;i<2;i++){
            temp=temp%q[i];
            if(!temp){
                cout<<"YES"<<endl;
                break;
            }
        }
        if(temp) cout<<"NO"<<endl;
    }
    system("pause");
    return 0;
}