#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<int, int> PII;
vector<PII> a;
long long n, t, l, r, ans;
int main()
{
    cin >> n;
    ans = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> t >> r;
        l = t - r;
        r = t + r;
        a.push_back({l, r});
    }
    sort(a.begin(), a.end(), [](PII t1, PII t2)
         { return t1.first < t2.first; });
    int al = -2e9, ar = -2e9;
    for (auto i : a)
    {
        int ml = i.first, mr = i.second;
        if (ml > ar)
        {
            ans += ml - ar;
            al = ml;
            ar = mr;
        }
        else if (mr > ar)
        {
            ar = mr;
        }
    }
    cout << ans << endl;

    return 0;
}