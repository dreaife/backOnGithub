#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10;
int n,T;
int q[N];
int q1(int a,int b){
    cout<<'?'<<' '<<1<<' '<<a<<' '<<b<<' '<<n-1<<endl;
    int t=0;
    fflush(stdout);
    cin>>t;
    return t;
}
int q2(int a,int b){
    cout<<'?'<<' '<<2<<' '<<a<<' '<<b<<' '<<1<<endl;
    int t=0;
    fflush(stdout);
    cin>>t;
    return t;
}
int main(){
    memset(q,0,N);
    cin>>T;
    while(T--){
        cin>>n;
        int max_pos=n;
        for(int i=1;i+1<=n;i+=2){
            int temp=q1(i,i+1);
            if(temp==n){
                max_pos=i+1;
                break;
            }else if(temp==n-1){
                temp=q1(i+1,i);
                if(temp==n){
                    max_pos=i;
                    break;
                }
            }
        }
        q[max_pos]=n;
        for(int i=1;i<=n;i++){
            int temp=q2(i,max_pos);
            q[i]=temp;
        }
        cout<<'!';
        for(int i=1;i<=n;i++)
            cout<<' '<<q[i];
        cout<<endl;
    }
    return 0;
}