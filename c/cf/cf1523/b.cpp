#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N=1e3+10;
ll q[N];
int main(){
    int t=0;cin>>t;
    while(t--){
        int n=0;cin>>n;
        for(int i=1;i<=n;i++) cin>>q[i];
        cout<<3*n<<endl;
        for(int i=1;i<=n;i+=2){
            cout<<"2 "<<i<<' '<<i+1<<endl;
            cout<<"1 "<<i<<' '<<i+1<<endl;
            cout<<"2 "<<i<<' '<<i+1<<endl;
            cout<<"1 "<<i<<' '<<i+1<<endl;
            cout<<"2 "<<i<<' '<<i+1<<endl;
            cout<<"1 "<<i<<' '<<i+1<<endl;
        }
    }
    system("pause");
    return 0;
}