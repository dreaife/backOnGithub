#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define int ull
ull l,r,ans,p;
int cnt[100],primes[20]={2,3,5,7,11,13,17,19,23,29,31};
ull mypow(ull a,ull b){
    ull ans = 1;
    while(b){
        if(b&1) ans *= a;
        a *= a;
        b>>=1;
    }return ans;
}
int getNum(int k,int L,int R){
    int l = 2,r = sqrt(R),res;
    while(l<r){
        int mid = (l + r )>> 1;
        if(mypow(mid,k)>=R) r = mid;
        else l = mid+1;
    }if(mypow(l,k)<=R && mypow(l,k) >= L)
        res = l;
    else return 0;
    l = 2,r = sqrt(R);
    while(l<r){
        int mid = (l+r+1) >> 1;
        if(mypow(mid,k) <= L) l = mid;
        else r = mid-1;
    }res = l-res;
    return res;
}
signed main(){
    while(cin>>l>>r){
        if(!r && !r) break;
        memset(cnt,0,sizeof cnt);p=0;ans=0;
        for(int i=64;i>=2;i--){
            cnt[i] = getNum(i,l,r);
        }for(int i=2;i<=64;i++){
            for(int j=0;i*j<=64;j++) cnt[i] -=cnt[i*j];
            if(cnt[i]) ans += cnt[i],p++;
        }cout<<r-l+1-p+ans<<endl;
    }
    return 0;
}