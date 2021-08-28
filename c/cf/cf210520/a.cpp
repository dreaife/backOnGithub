#include<bits/stdc++.h>
using namespace std;
int main(){
    int t=0;
    cin>>t;
    while(t--){
        unsigned int n=0,nn=0;
        cin>>n;
        while(n){
            n>>=1;
            nn++;
        }
        cout<<(1<<nn-1)-1<<endl;
    }
    system("pause");
    return 0;
}