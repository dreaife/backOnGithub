#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=1e5+10;
int w[N][15],f[15][N];
int m=0;
int max(int a,int b,int c){
    return max(a,max(b,c));
}
int main(){
    int n=0;
    int x,t,maxn=0;
    while(scanf("%d",&n)&&n){
        memset(f,0,sizeof f);
        for(int i=0;i<n;i++){
            scanf("%d %d",&x,&t);
            f[x][t]++;
            maxn=max(maxn,t);
        }
        for(int i=maxn-1;i>=0;i--){
            f[0][i]+=max(f[0][i+1],f[1][i+1]);
            f[10][i]+=max(f[10][i+1],f[9][i+1]);
            for(int j=1;j<=9;j++){
                f[j][i]+=max(f[j-1][i+1],f[j][i+1],f[j+1][i+1]);
            }
        }
        printf("%d\n",f[5][0]);
    }
    //system("pause");
    return 0;
}