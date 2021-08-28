#include<bits/stdc++.h>
using namespace std;
int main(){
    int t=0;
    cin>>t;
    while(t--){
        int n=0,ans=0;
        cin>>n;
        for(int i=31;i>=0;i--)
            if((n>>i)!=0){
                ans=1<<i;
                break;
            }
        cout<<ans-1<<endl;
    }
    system("pause");
    return 0;
}