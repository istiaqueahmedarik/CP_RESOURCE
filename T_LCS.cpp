#include <bits/stdc++.h>
#define int long long
#define float double
#define endl '\n'
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);

using namespace std;

int32_t main()
{
    IOS;
    string a, b;
    cin >> a >> b;
    int n = a.size(), m = b.size();
    int dp[n + 1][m + 1] = {0};
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (a[i - 1] == b[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    string ans = "";
    int i = n, j = m;
    while (i != 0 && j != 0)
    {
        if (dp[i - 1][j] == dp[i][j])
        {
            i--;
        }
        else if (dp[i][j - 1] == dp[i][j])
        {
            j--;
        }
        else
        {
            ans = b[j - 1] + ans;
            i--, j--;
        }
    }
    cout << ans << endl;

    return 0;
}