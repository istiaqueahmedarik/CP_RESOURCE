#include <bits/stdc++.h>
using namespace std;
unordered_map<int, vector<int>> adj;
int n, e;
vector<int> indegree;
vector<int> res;
vector<bool> vis;
void dfs()
{
    if (res.size() == n)
    {
        for (auto k : res)
            cout << k << " ";
        cout << endl;
    }
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i] && indegree[i] == 0)
        {
            vis[i] = 1;
            res.push_back(i);
            for (auto j : adj[i])
            {
                indegree[j]--;
            }
            dfs();
            vis[i] = 0;
            for (auto j : adj[i])
            {
                indegree[j]++;
            }
            res.pop_back();
        }
    }
}
int main()
{
    cin >> n >> e;
    indegree.resize(n + 1, 0);
    vis.resize(n + 1, 0);
    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        indegree[v]++;
    }
    dfs();
}