#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
//const int N = 1e5+10;
//int a[N];
int x1,p1,x2,p2;
int n1,n2;
//string s;
int check(int x){
    int n=0;
    while(x) n++,x/=10;
    return n;
}
void solve(){
    cin>>x1>>p1>>x2>>p2;
    n1 = check(x1),n2 = check(x2);
    if(n1>n2)
        for(int i=0;i<n1-n2;i++) x2*=10,p2--;
    else
        for(int i=0;i<n2-n1;i++) x1*=10,p1--;
    if(x1>x2)
        if(p1>=p2) cout<<">"<<endl;
        else cout<<"<"<<endl;
    else if(x1<x2)
        if(p1>p2) cout<<">"<<endl;
        else cout<<"<"<<endl;
    else if(x1 == x2)
        if(p1>p2) cout<<">"<<endl;
        else if(p1<p2) cout<<"<"<<endl;
        else cout<<"="<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int _;cin>>_;
    while(_--) solve();
    return 0;
}