#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
//const int N = 1e5+10;
int a[20];
int n,x,y,m,flag1,flag2;
//string s;
void solve(){
    cin>>n>>x>>y;
    for(int i=1;i<=n;i++) cin>>a[i];
    cin>>m;flag1 = flag2 = 0;
    for(int i=1,p;i<=m;i++){
        cin>>p;
        if(a[x+i]==a[x-i] && !flag2) flag2 = 0;
        else flag2 = 1;
        if(x<y){
            if(a[x+i]!=p) flag1 = -1;
        }else if(x>y){
            if(a[x-i]!=p) flag1 = -1;
        }if(i==m) if(!flag1)
            flag1 = 1;
    }if(flag1 == 1&&flag2) cout<<"Right"<<endl;
    else if(!flag1||!flag2) cout<<"Unsure"<<endl;
    else cout<<"Wrong"<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int _=1;
    while(_--) solve();
    return 0;
}