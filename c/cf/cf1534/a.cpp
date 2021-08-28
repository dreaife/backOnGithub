#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
const int N=60;
string w;
int n,m;
//string s;
void print(int p){
    if(!p){
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if((i+j)%2) cout<<'W';
                else cout<<'R';
            }cout<<endl;
        }
    }else{
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if((i+j)%2) cout<<'R';
                else cout<<'W';
            }cout<<endl;
        }
    }
}
void solve(){
    cin>>n>>m;
    int rj=0,ro=0,wj=0,wo=0;

    for(int i=1;i<=n;i++){
        cin>>w;
        for(int j=1;j<=m;j++){
            if(w[j-1]=='W'){
                if((i+j)%2) wj++;
                else wo++;
            }else if(w[j-1]=='R')
                if((i+j)%2) rj++;
                else ro++;
        }
    }
    int k=0;
    if((!rj&&!ro&&!wj&&!wo)||(!rj&&!ro&&!wj&&wo)||(!rj&&!ro&&wj&&!wo)||(!rj&&ro&&!wj&&!wo)||(rj&&!ro&&!wj&&!wo)) k=1;
    if((rj&&!ro&&wo&&!wj)||(!rj&&ro&&!wo&&wj)||k){
        cout<<"YES"<<endl;
        if(rj&&wo) print(1);
        else if(!rj&&wj) print(0);
        else{
            if(rj) print(1);
            else if(ro) print(0);
            else if(wj) print(0);
            else print(1);
        }

    }else{
        cout<<"NO"<<endl;
    }
    
}
int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int _=0;cin>>_;
    while(_--) solve();
    return 0;
}