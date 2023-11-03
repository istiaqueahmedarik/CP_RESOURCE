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
    map<int, int> mp;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        mp[arr[i]]++;
    }
    int mxFreq = -1, mxVal;
    for (auto i : mp)
    {
        if (i.second > mxFreq)
        {
            mxVal = i.first;
            mxFreq = i.second;
        }
    }
    int ans = 0;
    for (auto i : arr)
    {
        if (abs(mxVal - i) & 1)
            ans++;
    }
    cout << min(ans, n - ans) << endl;
}
auto main() -> int32_t
{
    IOS;
    int t = 1, cs = 1;
    while (t--)
    {
        solve();
    }

    return 0;
}