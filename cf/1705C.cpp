#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int N = 2e5 + 10;
#define int ll
int a[1000];
vector<PII> b;
int n, c, q, l, r, k;
char s[N];
int getPos(int pos)
{
    if (pos <= n)
        return pos;
    int p = lower_bound(a + 1, a + c + 2, pos) - a;
    pos -= a[p - 1];
    pos += b[p - 1].first - 1;
    return getPos(pos);
}
void solve()
{
    memset(a, 0x3f, sizeof a);
    b.clear();
    a[0] = 0;
    cin >> n >> c >> q >> s;
    a[1] = n;
    b.push_back({1, n});
    for (int i = 2; i <= c + 1; i++)
        cin >> l >> r, a[i] = r - l + 1, a[i] += a[i - 1], b.push_back({l, r});
    // for (int i = 0; i <= c + 1; i++)
    //     cout << a[i] << ' ';
    // cout << endl;
    while (q--)
    {
        cin >> k;
        int p = getPos(k);
        cout << s[p - 1] << endl;
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