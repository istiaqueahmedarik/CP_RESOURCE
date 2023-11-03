#include <bits/stdc++.h>
#define int long long
#define float double
#define endl '\n'
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);

using namespace std;

int32_t main()
{
    // IOS;
    int t;
    int cs = 1;
    while (cin >> t)
    {
        if (!t)
            break;
        map<int, vector<int>> adj;
        set<int> nodes;
        for (int i = 0; i < t; i++)
        {
            int a, b;
            cin >> a >> b;
            // cout << a << " " << b << endl;
            nodes.insert(a);
            nodes.insert(b);
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        while (1)
        {
            int a, b;
            cin >> a >> b;
            if (!a && !b)
                break;
            map<int, int> visited;
            queue<int> q;
            q.push(a);
            visited[a] = 1;
            map<int, int> level;
            level[a] = 0;
            while (!q.empty())
            {
                int node = q.front();
                q.pop();
                for (auto child : adj[node])
                {
                    if (!visited[child])
                    {
                        q.push(child);
                        level[child] = level[node] + 1;
                        visited[child] = 1;
                    }
                }
                visited[node] = 2;
            }
            int count = 0;
            for (auto i : nodes)
            {
                if (level[i] <= b && visited[i] == 2)
                    count++;
                // cout << "count: " << i << " " << level[i] << endl;
            }

            cout << "Case " << cs++ << ": " << nodes.size() - count << " nodes not reachable from node " << a << " with TTL = " << b << ".\n";
        }
    }
    return 0;
}