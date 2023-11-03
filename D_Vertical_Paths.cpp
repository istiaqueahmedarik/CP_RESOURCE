#include <bits/stdc++.h>
#define int long long
#define float double
#define endl '\n'
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);

using namespace std;
void dfs(int node, map<int, vector<int>> &adjList, unordered_map<int, int> &parent, unordered_map<int, bool> &visited)
{
    visited[node] = 1;
    for (auto i : adjList[node])
    {
        if (!visited[i])
        {
            parent[i] = node;
            dfs(i, adjList, parent, visited);
        }
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
        map<int, vector<int>> adjList;
        unordered_map<int, bool> visited;
        int root = 0;
        for (int i = 1; i <= n; i++)
        {
            int x;
            cin >> x;
            if (i == x)
            {
                root = x;
                continue;
            }
            adjList[i].push_back(x);
            adjList[x].push_back(i);
        }
        if (n == 1)
        {
            cout << 1 << endl
                 << 1 << endl
                 << 1 << endl;
            cout << endl;
            continue;
        }
        // for (auto i : adjList)
        // {
        //     cout << i.first << "-->";
        //     for (auto j : i.second)
        //     {
        //         cout << j << " ";
        //     }
        //     cout << endl;
        // }
        vector<int> leaf;
        for (auto i : adjList)
        {
            if (i.second.size() == 1 && i.first != root)
                leaf.push_back(i.first);
        }
        unordered_map<int, int> parent;
        dfs(root, adjList, parent, visited);
        visited.clear();
        parent[root] = root;
        vector<vector<int>> ans;
        for (auto i : leaf)
        {
            vector<int> temp;
            while (!visited[i])
            {
                temp.push_back(i);
                visited[i] = 1;
                i = parent[i];
            }
            reverse(temp.begin(), temp.end());
            ans.push_back(temp);
        }
        cout << ans.size() << endl;
        for (auto i : ans)
        {
            cout << i.size() << endl;
            for (auto j : i)
            {
                cout << j << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}