#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;
const int N = 1e5+10;
vector<queue<int>> pos(N);
vector<int> a(N);
void solve(){
    int n;cin>>n;
    for(int i=0;i<n;i++) {cin>>a[i];pos[a[i]].push(i);}
    sort(a.begin(),a.begin()+n);
    for(int i=0;i<n;i++){
        int check=abs(i-pos[a[i]].front()),k=0;
        pos[a[i]].pop();
        if(check%2){
            if(a[i]==a[i+1]){
                int check1=abs(i+1-pos[a[i+1]].front());
                if(check==check1) {i++;k=1;pos[a[i+1]].pop();}
            }
            if(!k) {cout<<"NO"<<endl;return;}
        }
    }
    cout<<"YES"<<endl;
}
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int _=0;cin>>_;
    while(_--) solve();
    return 0;
}