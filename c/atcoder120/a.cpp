#include<cstdio>
#include<algorithm>
#include<windows.h>
typedef long long ll;
const int N=2e5+10;
ll a[N],m[N];
using namespace std;
ll f(ll q[],int k){
    ll t=0;
    for(int i=0;i<k;i++){
        t+=q[i]+m[k-1];
        m[k-1]=q[i]+m[k-1];
    }
    return t;
}
int main(){
    int n;
    scanf("%d %lld",&n,&a[0]);
    m[0]=a[0];
    for(int i=1;i<n;i++){
        scanf("%lld",&a[i]);
        if(a[i]>m[i-1])
            m[i]=a[i];
        else
            m[i]=m[i-1];
    }
    for(int i=0;i<n;i++){
        printf("%lld",f(a,i+1));
    }
    system("pause");
    return 0;
}