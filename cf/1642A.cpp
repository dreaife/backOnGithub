#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<iomanip>
using namespace std;
typedef long long ll;
//const int N = 1e5+10;
struct poi{
    int x,y;
};poi a[10];
//int n;
//string s;
double ans;
void solve(){
    memset(a,0,sizeof a);
    ans = 0.0;
    for(int i=0,x,y;i<3;i++) cin>>x>>y,a[i].x=x,a[i].y=y;
    for(int i=0;i<3;i++){
        for(int j=i+1;j<3;j++){
            int p=3-i-j;
            if(a[i].x==a[j].x) continue;
            if(a[i].y==a[j].y) {if(a[p].y<a[i].y) ans+=abs(a[i].x-a[j].x);continue;}
            if(((a[p].x-a[i].x)/(a[j].x-a[i].x))-((a[p].y-a[i].y)/(a[j].y-a[i].y))<0){
                poi ta,tb;
                if(a[i].x<a[j].x) ta=a[i],tb=a[j]; 
                else ta=a[j],tb=a[i];
                double t = (tb.y-ta.y)/(tb.x-ta.x);
                if(!(ta.x+ta.y)||(t>0&&t<ta.y/ta.x)) ans+=sqrt((ta.x-tb.x)*(ta.x-tb.x)+(ta.y-tb.y)*(ta.y-tb.y));
            }else continue;
        }
    }
    cout<<fixed<<setprecision(8)<<ans<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int _;cin>>_;
    while(_--) solve();
    return 0;
}