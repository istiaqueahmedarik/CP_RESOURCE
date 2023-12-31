#pragma GCC optimize("O3")
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
    while (t--)
    {
        []()
        {
            int n;
            cin >> n;
            vector<string> v(n);
            for (int i = 0; i < n; i++)
            {
                cin >> v[i];
            }
            vector<int> adj[27];
            for (int i = 1; i <= n - 1; i++)
            {
                string a = v[i - 1], b = v[i];
                for (int j = 0; j < a.size(); j++)
                {
                    if (j == b.size())
                    {
                        cout << "Impossible" << endl;
                        exit(0);
                    }
                    if (a[j] != b[j])
                    {
                        adj[a[j] - 'a'].push_back(b[j] - 'a');
                        break;
                    }
                }
            }
            vector<int> vis(27, 0);
            stack<int> ans;

            function<void(int, vector<bool> &)> dfs = [&](int u, vector<bool> &localVis) -> void
            {
                vis[u] = 1;
                localVis[u] = 1;
                for (auto v : adj[u])
                {
                    if (localVis[v])
                    {
                        cout << "Impossible" << endl;
                        exit(0);
                    }
                    if (!vis[v])
                    {
                        dfs(v, localVis);
                    }
                }
                ans.push(u);
            };

            for (int i = 0; i < 26; i++)
            {
                if (!vis[i])
                {
                    vector<bool> vis1(26, 0);
                    dfs(i, vis1);
                }
            }
            while (!ans.empty())
            {
                cout << char(ans.top() + 'a');
                ans.pop();
            }
            cout << endl;
        }();
    }

    return 0;
}