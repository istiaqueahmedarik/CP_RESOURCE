#include <bits/stdc++.h>
#define int long long
#define float double
#define endl '\n'
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);

using namespace std;
vector<int> adjList[100009];
void dfs(int src, vector<int> &visited)
{
    visited[src] = 1;
    for (auto i : adjList[src])
    {
        if (!visited[i])
        {
            dfs(i, visited);
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
        int n, m, l;
        cin >> n >> m >> l;
        for (int i = 0; i <= n; i++)
        {
            adjList[i].clear();
        }
        for (int i = 0; i < m; i++)
        {
            int a, b;
            cin >> a >> b;
            adjList[a].push_back(b);
        }
        vector<int> visited(n + 5);
        for (int i = 0; i < l; i++)
        {
            int x;
            cin >> x;
            dfs(x, visited);
        }
        int c = 0;
        for (int i = 1; i <= n; i++)
        {
            c += visited[i] == 1;
        }
        cout << c << endl;
    }
    return 0;
}