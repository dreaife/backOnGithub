#include<iostream>
#include<algorithm>
#include<cstring>
#include<unordered_map>
#include<vector>
using namespace std;
const int N = 1e6+10;
int n,a[N],b[N];

void solve(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++) scanf("%d",&b[i]);

    printf("yes\n");
}

int main(){
    int _;scanf("%d",&_);
    while(_--) solve();
    return 0;
}