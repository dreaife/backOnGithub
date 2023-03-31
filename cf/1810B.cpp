#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
#define endl '\n'
#define all(v) v.begin(),v.end()
typedef long long ll;
typedef pair<int,int> PII;

//const int N = 2e5+10;
//int a[N];
int n,m,a[100];
//string s;
void solve(){
    cin>>n;m = 0;
    while(n > 1 && (n%2) && m<=40){
        if(!(n%2)) return void(cout<<-1<<endl);
        int t1 = n+1,t2 = n-1;
        t1 /= 2;t2 /= 2;
        if(t1%2) a[m++] = 1,n=t1;
        else if(t2%2) a[m++] = 2,n=t2;
        else return void (cout<<-1<<endl);
    }if(n != 1) return void(cout<<-1<<endl);
    cout<<m<<endl;
    for(int i=m-1;i>=0;i--) cout<<a[i]<<' ';
    cout<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int _;cin>>_;
    while(_--) solve();
    return 0;
}