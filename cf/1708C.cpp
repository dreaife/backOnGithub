#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int N = 1e5 + 10;
int a[N];
int n, q, ans;
void solve()
{
    cin >> n >> q;
    string s;
    ans = 0;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = n - 1; ~i; i--)
    {
        if (ans >= a[i])
            s = "1" + s;
        else
        {
            if (q > ans)
                ans++, s = "1" + s;
            else
                s = "0" + s;
        }
    }
    cout << s << endl;
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