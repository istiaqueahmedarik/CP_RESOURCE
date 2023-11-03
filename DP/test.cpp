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
vector<vector<int>> dp(1000, vector<int>(1000, -1));
int ans(int chance, int sm)
{
    if (sm == 0 && chance == 0)
        return 1;
    if (sm < 0 || !chance)
        return 0;

    if (dp[chance][sm] != -1)
        return dp[chance][sm];
    int total = 0;
    for (int i = 1; i <= 6; i++)
        total += ans(chance - 1, sm - i);

    return dp[chance][sm] = total;
}
void solve()
{
    int n, k;
    cin >> n >> k;
    cout << ans(n, k) << endl;
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