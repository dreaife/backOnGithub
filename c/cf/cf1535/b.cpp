#include<iostream>
#include<cstring>
#include<algorithm>
#include<windows.h>
typedef long long ll;
using namespace std;
const int N=2010;
int q[N];
int gcd(int m,int n){
	int rem;
	while(n > 0){
		rem = m % n;
		m = n;
		n = rem;
	}
	return m;
}
int main(){
    int T=0;cin>>T;
    while(T--){
        int n=0;cin>>n;
        int n0=0,i=0,n1=0,t=0;
        ll ans=0;
        while(i+n0<n){
            int temp;cin>>temp;
            if(temp%2==0) n0++;
            else q[i++]=temp;
        }
        sort(q,q+i);
        ans+=n0*(n-n0)+n0*(n0-1)/2;
        for(i=0;i<n-n0;i++){
            if(q[i]==1) continue;
            for(int j=i+1;j<n-n0;j++)
                if(gcd(q[i],2*q[j])!=1)
                    ans++;
        }
        cout<<ans<<endl;
    }
    system("pause");
    return 0;
}