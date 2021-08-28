#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 2e5 + 1;
int n,k;
int w[N],st[N],cnt[N];
struct node {
  int w, id;
  bool operator < (const node &x) const{
    return w < x.w;
  }
}a[N];
void solve(){
  memset(st, 0, sizeof st);
  cin >> n >> k;
  for (int i = 1; i <= n; i ++ )
    cin >> a[i].w, a[i].id = i;
  sort(a + 1, a + 1 + n);
  int cnt = 0;
  for (int i = 1, j = 0; i <= n; i ++ )
    if (st[a[i].w] == k)
      w[a[i].id] = 0;
    else 
      w[a[i].id] = j + 1, st[a[i].w] ++ , j = (j + 1) % k, cnt ++ ;
  if (cnt % k){
    cnt %= k;
    for (int i = n; i >= 1 and cnt; i -- )
      if (!w[a[i].id])
        continue;
      else 
        w[a[i].id] = 0, cnt -- ;
  }
  for (int i = 1; i <= n; i ++ )
    cout << w[i] << ' ';
  cout << endl;
}

int main(){
  int t;
  cin >> t;
  while (t -- )
    solve();
  return 0;
}
