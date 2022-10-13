#include<iostream>
#include<cstring>
#include<algorithm>
#include<set>
using namespace std;
#define endl '\n'
#define all(v) v.begin(),v.end()
typedef long long ll;
typedef pair<int,int> PII;

//const int N = 2e5+10;
//int a[N];
//int n;
//string s;
char a[10][10];
void solve(){
    for(int i=0;i<8;i++) for(int j=0;j<8;j++)
        cin>>a[i][j];
    for(int i=0;i<8;i++) {
        int j=0;
        while((a[i][j] != '.' && a[i][j] != 'B') && j<8) j++;
        if(j==8) return void(cout<<"R"<<endl);
    }
    cout<<"B"<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int _;cin>>_;
    while(_--) solve();
    return 0;
}