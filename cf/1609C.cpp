#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
typedef long long ll;
const int N = 2e5+10;
int a[N];
int n,e,ans;
bool isPrime[N];
int Prime[N/4], cnt = 0;
void GetPrime(int n){
	memset(isPrime, 1, sizeof(isPrime));
	isPrime[1] = 0;
	for(int i = 2; i <= n; i++){
		if(isPrime[i])
			Prime[++cnt] = i;
		for(int j = 1; j <= cnt && i*Prime[j] <= n/*不超上限*/; j++){
			isPrime[i*Prime[j]] = 0;
			if(i % Prime[j] == 0)
				break;
		}
	}
}
bool find(int k){
    int l=0,r=N/4;
    while(l<=r){
        int mid = l+r>>1;
        if(Prime[mid]<=k) l=mid;
        else r=mid-1;
    }if(Prime[l] != k) return false;
    else return true;
}
void solve(){
    cin>>n>>e;int km = n/e,lm = n - e;ans = 0;
    for(int i=1;i<=n;i++) cin>>a[i];
    if(!km||e==n) return cout<<0<<endl,void();
    for(int i=1;i<=e;i++){
        int np=0,n1=0;
        for(int j=1;i+j*e<=n;j++){
            if(!isPrime[a[i+j*e]]&&(a[i+j*e]-1)){
                int t = np + n1;
                ans += (t-1)*t/2;
                np = 0,n1 = 0;
            }if(a[i+j*e]-1==0) n1++;
            if(isPrime[a[i+j*e]]){

            }
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int _;cin>>_;
    while(_--) solve();
    return 0;
}