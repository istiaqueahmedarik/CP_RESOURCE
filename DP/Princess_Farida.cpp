#include <bits/stdc++.h>
#define int long long
#define float double
#define endl '\n'
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);

using namespace std;
int solve(int n, int dp[], vector<int> &v)
{
    if (dp[n])
        return dp[n];
    dp[0] = v[0];
    dp[1] = max(v[0], v[1]);
    dp[2] = max(v[0] + v[2], v[1]);
    for (int i = 3; i <= n; i++)
    {
        dp[i] = max(dp[i - 1], dp[i - 2] + v[i]);
    }
    return dp[n];
}
int32_t main()
{
    IOS;
    int t;
    cin >> t;
    int cs = 1;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        int dp[n];
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            dp[i] = 0;
        }
        int ans = v.empty() ? 0 : solve(n - 1, dp, v);
        cout << "Case " << cs++ << ": " << ans << endl;
    }
    return 0;
}