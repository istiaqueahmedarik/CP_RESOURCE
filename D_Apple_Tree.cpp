#include <bits/stdc++.h>
#define int long long
#define float double
#define endl '\n'
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);

using namespace std;
map<int, int> visited;
map<int, vector<int>> adj;
map<int, int> last;
void countLeaf(int start)
{
    visited[start] = 1;
    if (adj[start].size() == 1 && start != 1)
        last[start] = 1;
    for (auto i : adj[start])
    {
        if (!visited[i])
        {
            countLeaf(i);

            last[start] += last[i];
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
        visited.clear();
        adj.clear();
        int n;
        cin >> n;
        for (int i = 0; i < n - 1; i++)
        {
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        last.clear();
        countLeaf(1);
        int q;
        cin >> q;
        if (last[1] == 0)
            last[1] = 1;
        while (q--)
        {
            int x, y;
            cin >> x >> y;
            cout << last[x] * last[y] << endl;
        }
    }
    return 0;
}