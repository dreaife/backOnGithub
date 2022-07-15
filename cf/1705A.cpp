#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int N = 1010;
int a[N];
int n, x;
// string s;
void solve()
{
    cin >> n >> x;
    for (int i = 0; i < 2 * n; i++)
        cin >> a[i];
    sort(a, a + 2 * n);
    for (int i = 0; i < n; i++)
        if (a[i + n] - a[i] < x)
            return void(cout << "NO" << endl);
    return void(cout << "YES" << endl);
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