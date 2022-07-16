#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int N = 2e5 + 10;
#define int ll
int a[N];
struct T
{
    int l, r;
} b[N];
int n, c, q, l, r, k;
string s;
int getPos(int &pos)
{
    int p = lower_bound(a + 1, a + c + 2, pos) - a;
    while (p != 1)
    {
        int d = pos - a[p - 1];
        pos = b[p].l + d - 1;
        p = lower_bound(a + 1, a + c + 2, pos) - a;
    }
    return pos;
}
void solve()
{
    cin >> n >> c >> q >> s;
    a[1] = n;
    b[1] = {1, n};
    for (int i = 2; i <= c + 1; i++)
        cin >> l >> r, a[i] = r - l + 1, a[i] += a[i - 1], b[i] = {l, r};
    // for (int i = 0; i <= c + 1; i++)
    //     cout << a[i] << ' ';
    // cout << endl;
    while (q--)
    {
        cin >> k;
        int p = getPos(k);
        cout << s[k - 1] << endl;
    }
}
signed main()
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