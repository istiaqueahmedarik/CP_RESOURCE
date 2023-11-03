#include <bits/stdc++.h>
using namespace std;

int visited[1000];
int dist[1000];
int parent[1000];
vector<pair<int, int>> adj[1000];

bool bellman_ford(int src, int nodes)
{
    for (int i = 0; i < nodes; i++)
    {
        dist[i] = INT_MAX;
        parent[i] = -1;
    }
    dist[src] = 0;
    for (int i = 0; i < nodes - 1; i++)
    {
        for (int j = 0; j < nodes; j++)
        {
            for (auto it : adj[j])
            {
                if (dist[j] != INT_MAX && dist[it.first] > dist[j] + it.second)
                {
                    dist[it.first] = dist[j] + it.second;
                    parent[it.first] = j;
                }
            }
        }
    }
    for (int j = 0; j < nodes; j++)
    {
        for (auto it : adj[j])
        {
            if (dist[j] != INT_MAX && dist[it.first] > dist[j] + it.second)
            {
                return true;
            }
        }
    }
    return false;
}

void negative_path()
{
}

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
    if (bellman_ford(1, nodes))
    {
        cout << "Yes" << endl;
        negative_path();
    }
    else
    {
        cout << "No" << endl;
    }
}