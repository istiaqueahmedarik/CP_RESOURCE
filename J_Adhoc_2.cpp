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
vector<int> v;
int n, k;

void solve()
{
    cin >> n >> k;
    v.push_back(0);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.emplace_back(x);
    }
    vector<vector<int>> dp(n + 5, vector<int>(k + 5));
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            if (i == 1)
                dp[i][j] = (!v[i] | v[i] == j);
            else if (v[i] == j || !v[i])
                dp[i][j] = ((dp[i - 1][j - 1] + dp[i - 1][j]) % MOD + dp[i - 1][j + 1]) % MOD;
            else
                dp[i][j] = 0;
        }
    }
    for (int i = 1; i <= k; i++)
    {
        ans = (ans + dp[n][i]) % MOD;
    }
    cout << ans << endl;
}
auto main() -> int32_t
{
    IOS;
    solve();

    return 0;
}