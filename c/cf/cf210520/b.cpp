#include<bits/stdc++.h>
using namespace std;
int main(){
    int t=0;
    cin>>t;
    while(t--){
        int n=0,n0=0,mid=1;
        int ac=0,bc=0;
        cin>>n;
        char s[n],che[n];
        memset(che,'1',sizeof che);
        for(int i=0;i<n;i++){
            cin>>s[i];
            if(i<n/2&&!(s[i]-'0'))
                n0++;
        }
        if(!(n-1)) n0++;
        if(n%2==1)
            if(!(s[n/2+1]-'0'))
                mid=(int)s[n/2+1];
        if(n0%2==0&&mid==0)
            cout<<"ALICE"<<endl;
        else if(n0%2!=0)
            cout<<"BOB"<<endl;
        else
            cout<<"DRAW"<<endl;
    }
    system("pause");
    return 0;
}