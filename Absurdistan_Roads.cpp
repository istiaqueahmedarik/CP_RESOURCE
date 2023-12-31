#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "debug.h"
#endif // !ONLI
using namespace std;
#define int long long
#define pi acos(-1)
#define endl '\n'
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
#define FileIO                        \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout)
const int MOD = 1e9 + 7, dx[] = {1, 0, -1, 0, 1, -1, -1, 1}, dy[] = {0, 1, 0, -1, 1, 1, -1, -1};
auto main() -> int32_t
{
    IOS;
    int t = 1, cs = 1;
    cin >> t;
    while (t--)
    {
        function<void()> solve = [&]()
        {
            int n;
            while (cin >> n)
            {
                vector<vector<int>> adj(n + 1, vector<int>(n + 1, 0));
                for (int i = 1; i <= n; i++)
                {
                    for (int j = 1; j <= n; j++)
                    {
                        cin >> adj[i][j];
                    }
                }

                bool mp[n + 1][n + 1] = {0};

                for (int k = 1; k <= n; k++)
                    for (int i = 1; i <= n; i++)
                        for (int j = 1; j <= n; j++)
                        {
                            if (mp[i][k])
                                break;
                            if (i != j && j != k && i != k)
                            {
                                if (adj[i][j] == adj[i][k] + adj[k][j])
                                {
                                    mp[i][j] = 1;
                                }
                            }
                        }
                pair<int, pair<int, int>> p;
                int cnt = 0;
                for (int i = 1; i <= n; i++)
                {
                    for (int j = i + 1; j <= n; j++)
                    {
                        if (!mp[i][j])
                        {
                            cout << i << " " << j << " " << adj[i][j] << endl;
                            p = {i, {j, adj[i][j]}};
                            cnt++;
                        }
                    }
                }
                if (cnt != n)
                    cout << p.first << " " << p.second.first << " " << p.second.second << endl;

                cout << endl;
            }
        };
        solve();
    }

    return 0;
}