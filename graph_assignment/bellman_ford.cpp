#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int parent[N], dt[N];
vector<pair<int, int>> adj[N];

int main()
{
    int nodes, edges;
    cin >> nodes >> edges;
    for (int i = 0; i < edges; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }
    for (int i = 1; i <= nodes; i++)
    {
        dt[i] = INT_MAX;
    }

    bool negative_cycle = false;
    int last_node = -1;

    for (int i = 1; i <= nodes; i++)
    {
        for (int node = 1; node <= nodes; node++)
        {
            for (auto adj_pair : adj[node])
            {
                int u = node;
                int v = adj_pair.first;
                int w = adj_pair.second;
                int lhs = dt[u] + w;
                int rhs = dt[v];
                if (lhs < rhs)
                {
                    rhs = lhs;
                    parent[v] = u;
                    if (i == nodes)
                    {
                        negative_cycle = true;
                        last_node = v;
                    }
                }
            }
        }
    }

    if (negative_cycle)
    {
        cout << "YES" << endl;

        int curr = last_node;
        for (int i = 1; i < nodes; i++)
        {
            curr = parent[curr];
        }

        int first = curr;

        vector<int> cycle;
        cycle.push_back(curr);
        while (1)
        {
            curr = parent[curr];
            cycle.push_back(curr);
            if (curr == first)
            {
                break;
            }
        }
        reverse(cycle.begin(), cycle.end());
        for (auto x : cycle)
        {
            cout << x << " ";
        }
        cout << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}