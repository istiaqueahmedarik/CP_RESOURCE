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
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int time = 100;
    map<int, int> ans;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int pos = arr[j] * i;
            ans[pos]++;
        }
    }
    int a = -1, ind = 0;
    for (auto i : ans)
    {
        if (i.first <= n)
            a = max(i.second, a);
        else
            break;
    }
    cout << max(0LL, a) << endl;
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