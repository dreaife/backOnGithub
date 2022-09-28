#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
#define int long long
const int N = 1010;
double g[N][N],dis[N];
int n,a[N],b[N],x1,y11,x2,y2,st[N],v1,v2;

double calc(int x1,int y1,int x2,int y2){
    return sqrt((x1-x2)*(x1-x2)*1.0+(y1-y2)*(y1-y2)*1.0);
}
double dij(){
    for(int i=1;i<=n;i++) dis[i] = 1e18;
    dis[1] = 0;
    for (int i = 0; i < n; i ++ ){
        int t = -1;
        for (int j = 1; j <= n; j ++ ) if(!st[j] && (t==-1 || dis[t]>dis[j]))
                t = j;
        for (int j = 1; j <= n; j ++ )
            dis[j] = min(dis[j], dis[t] + g[t][j]);
        st[t]++;
    }//if (dis[n] == 1e18) return -1;
    return dis[n];
}
signed main()
{
    cin>>n;n+=2;
    for(int i=2;i<n;i++) cin>>a[i]>>b[i];
    cin>>x1>>y11>>x2>>y2>>v1>>v2;
    g[1][n]=double(calc(x1,y11,x2,y2)*1.0/(v1*1.0));
    for(int i=2;i<n;i++) g[1][i]=calc(x1,y11,a[i],b[i])/(v1*1.0);
    for(int i=2;i<n;i++){
        double t = calc(a[i],b[i],x2,y2);
        if((t / (v2*1.0))<=3) g[i][n] = double(t/(1.0*v2));
        else g[i][n] = 3.0 + (t-v2*3.0)/(1.0*v1);
    }
    for(int i=2;i<n;i++){
        for(int j=2;j<n;j++){
            if(i==j) continue;
            double tp=calc(a[i],b[i],a[j],b[j]);
            if(tp/(v2*1.0)<=3) g[i][j]=tp/(v2*1.0);
            else g[i][j]=3.0+(tp-v2*3.0)/(v1*1.0);
        }
    }printf("%.8lf\n",dij());
    return 0;
}