#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e3 + 3;
int dp[N][N];

int32_t main()
{
    int nodes, edges, queries;
    cin >> nodes >> edges >> queries;
    for (int i = 1; i <= nodes; i++)
    {
        for (int j = 1; j <= nodes; j++)
        {
            dp[i][j] = 1e18;
        }
    }

    for (int i = 0; i < edges; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        dp[u][v] = min(dp[u][v], w);
        dp[v][u] = min(dp[v][u], w);
    }

    for (int i = 1; i <= nodes; i++)
    {
        dp[i][i] = 0;
    }

    for (int k = 1; k <= nodes; k++)
    {
        for (int i = 1; i <= nodes; i++)
        {
            for (int j = 1; j <= nodes; j++)
            {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }

    for (int i = 0; i < queries; i++)
    {
        int u, v;
        cin >> u >> v;
        if (dp[u][v] == 1e18)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << dp[u][v] << endl;
        }
    }
}