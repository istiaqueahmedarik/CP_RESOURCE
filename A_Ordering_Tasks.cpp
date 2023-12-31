/*******************************************
 @b |I|s|t|i|a|q|u|e| |A|h|m|e|d| |A|r|i|k|
********************************************/
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include "debug.h"
#endif // !ONLI
#define int long long
#define pi acos(-1)
#define endl '\n'
#define set_bits __builtin_popcountll
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
#define FileIO                        \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout)
///@b decltype and const
const int MOD = 1e9 + 7, dx[] = {1, 0, -1, 0, 1, -1, -1, 1}, dy[] = {0, 1, 0, -1, 1, 1, -1, -1};
auto main() -> int32_t
{
    IOS;
    int t = 1, cs = 1;
    while (t--)
    {
        []() -> void
        {
            while (1)
            {
                int n, e;
                cin >> n >> e;
                if (!n && !e)
                    break;
                unordered_map<int, vector<int>> adjList;
                unordered_map<int, bool> visited;
                stack<int> trop;
                while (e--)
                {
                    int u, v;
                    cin >> u >> v;
                    adjList[u].push_back(v);
                }

                function<void(int)> dfs = [&](int u) -> void
                {
                    visited[u] = true;
                    for (auto v : adjList[u])
                    {
                        if (!visited[v])
                            dfs(v);
                    }
                    trop.push(u);
                };

                for (int i = 1; i <= n; i++)
                {
                    if (!visited[i])
                    {
                        dfs(i);
                    }
                }
                while (!trop.empty())
                {
                    cout << trop.top() << " ";
                    trop.pop();
                }
                cout << endl;
            }
        }();
    }

    return 0;
}