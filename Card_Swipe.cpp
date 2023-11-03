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
    int mx = LLONG_MIN;
    set<int> s;
    map<int, bool> has;
    while (n--)
    {
        int x;
        cin >> x;
        if (has[x])
        {
            has[x] = false;
            s.erase(x);
        }
        else
        {
            has[x] = true;
            s.insert(x);
        }
        int sz = s.size();
        mx = max(sz, mx);
    }
    cout << mx << endl;
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