#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int N = 2e5 + 10;
int a[N];
int n;
ll ans;
// string s;
void solve()
{
    cin >> n;
    ans = 0;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n - 1; i++)
    {
        if (!a[i])
            continue;
        ll len = 0, tp = i, sto = 0;
        while (a[i] && i < n - 1)
            sto += a[i++];
        while (a[i] == 0 && i++ < n - 1)
            len++;
        i--;
        // cout << sto << ' ' << len << ' ' << i << endl;
        ans += sto + len;
    }
    cout << ans << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int _;
    cin >> _;
    while (_--)
        solve();
    return 0;
}