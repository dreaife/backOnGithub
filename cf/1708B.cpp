#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>
using namespace std;
typedef long long ll;
const int N = 1e5 + 10;
int a[N];
int n, l, r;
// string s;
void solve()
{
    cin >> n >> l >> r;
    // if (r - l + 1 < n)
    //     return void(cout << "NO" << endl);
    for (int i = n; i >= 1; i--)
    {
        if (r / i * i < l)
            return void(cout << "NO" << endl);
        a[i] = r / i * i;
    }
    cout << "YES" << endl;
    for (int i = 1; i <= n; i++)
        cout << a[i] << ' ';
    cout << endl;
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