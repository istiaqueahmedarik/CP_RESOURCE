#include <bits/stdc++.h>
#define int long long
#define float double
#define endl '\n'
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);

using namespace std;
const int N = 2023;
int dp[N][N];
vector<int> level[(N + 1) * (N + 2) / 2];
void pre()
{
    int temp = 1;
    for (int i = 1; i < N; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            level[temp].push_back(i);
            level[temp].push_back(j);
            dp[i][j] = temp * temp;
            if (i > 0)
            {
                dp[i][j] += dp[i - 1][j];
                if (j > 0)
                {
                    dp[i][j] += dp[i - 1][j - 1];
                    if (i > 1)
                    {
                        dp[i][j] -= dp[i - 2][j - 1];
                    }
                }
            }
        }
        temp++;
    }
}
int32_t main()
{
    IOS;
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a = level[n][0];
        int b = level[n][1];
        cout << dp[a][b] << endl;
    }
    return 0;
}