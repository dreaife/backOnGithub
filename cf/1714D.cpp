#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
#define endl '\n'
#define all(v) v.begin(),v.end()
typedef long long ll;
typedef pair<int,int> PII;

//const int N = 2e5+10;
//int a[N];
int q,n,cnt[200],lot;
string t,s[20];
void solve(){
    vector<PII> ans;
    cin>>t>>n;
    for(int i=0;i<n;i++) cin>>s[i];lot = t.length();
    for(int i=0;i<lot;i++) cnt[i]=0;
    sort(s,s+n,[](string t1,string t2){
        return t1.length()>t2.length();
    });
    for(int i=0;i<n;i++){
        string tp = s[i];
        for(int j=0;j<t.length()-tp.length()+1;j++){
            if(lot==0) break;
            if(t.substr(j,tp.length()) == tp){
                int f=0;
                for(int k=j;k<j+tp.length()-1;k++)
                    if(!cnt[k]++) f++;
                if(f) lot-=f,ans.push_back({i,j}),cout<<i<<' '<<j<<endl;
            }
        }
    }if(lot) return void(cout<<-1<<endl);
    cout<<ans.size();
    for(auto i:ans) cout<<i.first<<' '<<i.second<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int _;cin>>_;
    while(_--) solve();
    return 0;
}