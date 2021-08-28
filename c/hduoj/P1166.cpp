#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;
typedef long long ll;
const int N = 1e5+10;
int a[N],c[N];
int n;
string s;

inline int lowbit(int x){
    return x & (-x);
}

void update(int x,int k){
    for(int i=x;i<=n;i+=lowbit(i)) c[i]+=k;
}

int getsum(int x){
    int sum=0;
    while(x){
        sum+=c[x];
        x-=lowbit(x);
    }
    return sum;
}

void solve(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        c[i]+=a[i];
        if(i+lowbit(i)<=n) c[i+lowbit(i)]+=c[i];
    }
    string s;
    int x,y;
    while(cin>>s && s[0]!='E'){
        cin>>x>>y;
        if(s[0]=='A')
            update(x,y);
        else if(s[0]=='S')
            update(x,-y);
        else{
            int ans = getsum(y) - getsum(x-1);
            cout<<ans<<endl;
        }
    }
}

int main(){
    int T;cin>>T;
    for(int i=1;i<=T;i++){
        cout<<"Case "<<i<<":"<<endl;
        memset(a,0,sizeof a);memset(c,0,sizeof c);
        solve();
    }
    return 0;
}