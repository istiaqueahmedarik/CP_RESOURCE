#include <bits/stdc++.h>
using namespace std;
#define int long long
#define float double
#define endl '\n'
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
// decltype
const float pi = 3.141592653589793238462643383279502884197;
const int MOD = 1e9 + 7, dx[] = {1, 0, -1, 0, 1, -1, -1, 1}, dy[] = {0, 1, 0, -1, 1, 1, -1, -1};
void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    vector<int> diff;
    for (int i = 0; i < n - 1; i++)
        diff.push_back(v[i + 1] - v[i]);
    int mn = *min_element(diff.begin(), diff.end());
    if (mn < 0)
        cout << 0 << endl;
    else
        cout << mn / 2 + 1 << endl;
}
auto main() -> int32_t
{
    IOS;
    int t, cs = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}
/*
9




2->2
3->2
4->3
5->3
*/