#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N=1e3+10;
int a[N],p[N];
int main(){
    int t=0;cin>>t;
    while(t--){
        p[0]=0;
    int n,m,n0=0,k=1;
        cin>>n>>m;
        memset(a,0,N),memset(p,0,N);
        char temp[N];
        cin>>temp;
        if(m>n) m=n;
        for(int i=1;i<=n;i++){
            a[i]=temp[i-1]-'0';
            if(a[i]==0) n0++;
            if(a[i]==1) p[k++]=i;
        }
        if(n0!=n&&n0!=0){
            for(int i=1;i<=n-n0;i++){
                if(p[i]-p[i-1]>1){
                    if(p[i]-p[i-1]-1<=m*2){
                        for(int j=p[i-1];j<=p[i];j++)
                            a[j]=1;
                        if((p[i]-p[i-1]-1)&1) a[p[i-1]+(p[i]-p[i-1])/2]=0;
                    }else{
                        for(int j=p[i-1];j<=p[i-1]+m;j++)
                            a[j]=1;
                        for(int j=p[i];j>=p[i]-m;j--)
                            a[j]=1;
                        if((p[i]-p[i-1]-1)&1) a[p[i-1]+(p[i]-p[i-1])/2]=0;
                    }
                }
            }
            if(p[--k]<n){
                for(int i=p[k];i<=min(m+p[k],n);i++)
                    a[i]=1;
            }
            if(p[1]>1){
                for(int i=1;i<p[1];i++) a[i]=0;
                for(int i=p[1];i>=max(1,p[1]-m);i--)
                    a[i]=1;
            }
        }
        for(int i=1;i<=n;i++)
            cout<<a[i];
        cout<<endl;
    }
    system("pause");
    return 0;
}