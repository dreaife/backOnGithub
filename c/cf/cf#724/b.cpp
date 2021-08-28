#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N=1010;
string s,ans;
bool check(string t,int len){
    for(int i=0;i<s.size()-len+1;i++){
        string temp=s.substr(i,len);
        if(temp==t) return 0;
    }
    return 1;
}
void add(int n){
    ans[n]++;
    if(ans[n]>'z') ans[n]='a',add(n-1);
}
bool is(){
    int k=0;
    for(int i=0;i<ans.size();i++)
        if(ans[i]=='z') k++;
    return k==ans.size();
}
int main(){
    int t=0;cin>>t;
    while(t--){
        ans='a';
        int n=0,m=N,len=1;cin>>n;
        cin>>s;
        while(!check(ans,len)){
            if(is()){
                len++;ans='a';
                for(int i=1;i<len;i++) ans+='a';
            }else add(len-1);
        }
        cout<<ans<<endl;
    }
    return 0;
}