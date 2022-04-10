#include<bits/stdc++.h>
using namespace std;
const int N = 1e3+10;
int n,m,tr[N][2],ans[N],cnt[N][2],idx;
char str[N];
int main(){
    cin>>n>>m;
    while(n--){
        cin >> str;
        for(int i=0;i<m;i++) cnt[i][str[i]-'0']++;
    }
    for(int i=0;i<m;i++)
        if(cnt[i][0]>cnt[i][1]) ans[i]=0;
        else ans[i]=1;
    for(int i=0;i<m;i++) cout<<ans[i];
    return 0;
}