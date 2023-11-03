#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

vector<pair<int, int>> adj[N];

int visited[N];

int parent[N];

int nodes, edges;

int dt[N];

void pre(int size)
{
    for (int i = 1; i <= size; i++)
    {
        dt[i] = INT_MAX;
    }
}

void dijstra(int src)
{
    pre(nodes);

    // source to source distance is 0
    dt[src] = 0;

    // pq is for storing the pair of distance and node
    priority_queue<pair<int, int>> pq;

    pq.push({0, src});

    while (!pq.empty())
    {
        // get the node with minimum distance
        pair<int, int> head = pq.top();
        pq.pop();

        int curr_node = head.second;

        if (visited[curr_node])
            continue;

        visited[curr_node] = 1;

        for (auto adj_pair : adj[curr_node])
        {
            int lhs = dt[curr_node] + adj_pair.second;
            int rhs = dt[adj_pair.first];

            if (lhs < rhs)
            {
                // update the distance
                rhs = lhs;
                // update the parent
                parent[adj_pair.first] = curr_node;
                // push the node in the pq at the end, here minus represents the max heap
                pq.push({-rhs, adj_pair.first});
            }
        }
    }
}

int main()
{
    cin >> nodes >> edges;

    for (int i = 0; i < edges; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }

    dijstra(1);

    if (visited[nodes] == 0)
    {
        cout << "-1" << endl;
        return 0;
    }

    vector<int> path;
    int curr = nodes;
    while (1)
    {
        path.push_back(curr);
        if (curr == 1)
        {
            break;
        }
        curr = parent[curr];
    }
    reverse(path.begin(), path.end());

    for (auto node : path)
    {
        cout << node << " ";
    }

    return 0;
}