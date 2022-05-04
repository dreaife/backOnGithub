#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N = 110;
int n,m,v,len,px,py,tw=0;
int a[N][N],tw1[8]={-1,-1,0,1,1,1,0,-1},tw2[8]={0,1,1,1,0,-1,-1,-1};
char s[510];
void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>s;
        for(int j=0;j<m;j++){
            if(s[j]=='.') a[i][j+1]=0;
            else if(s[j]=='#') a[i][j+1]=1;
            else if(s[j]=='*') px=i,py=j+1,a[i][j+1]=0;
        }
    }cin>>len>>s;
    for(int i=0;i<len;i++){
        if(s[i]=='U') v++;
        else if(s[i]=='D') v--,v=max(v,0);
        else if(s[i]=='L') tw = (tw-1+8)%8;
        else if(s[i]=='R') tw = (tw+1+8)%8;
        if(!v) {cout<<px<<' '<<py<<endl;continue;}
        for(int i=px+tw1[tw],j=py+tw2[tw],k=0;k<v;k++,i+=tw1[tw],j+=tw2[tw]){
            if(i<1||i>n||j<1||j>m){
                cout<<"Crash! ";v = 0;
                px = i - tw1[tw],py = j - tw2[tw];
                cout<<px<<' '<<py<<endl;break;
            }if(tw%2){
                if((a[i][j-tw2[tw]]&&a[i-tw1[tw]][j])||a[i][j]){
                    cout<<"Crash! ";v = 0;
                    px = i - tw1[tw],py = j - tw2[tw];
                    cout<<px<<' '<<py<<endl;break;
                }
            }else{
                if(a[i][j]){
                    cout<<"Crash! ";v = 0;
                    px = i - tw1[tw],py = j - tw2[tw];
                    cout<<px<<' '<<py<<endl;break;
                }
            }if(k==v-1) px=i,py=j,cout<<px<<' '<<py<<endl;
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int _=1;
    while(_--) solve();
    return 0;
}