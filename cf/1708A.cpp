#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
ll a[1100];
int n;
void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    ll t = a[1];
    for (int i = 2; i <= n; i++)
    {
        if (a[i] % t)
            return void(cout << "NO" << endl);
    }
    cout << "YES" << endl;
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