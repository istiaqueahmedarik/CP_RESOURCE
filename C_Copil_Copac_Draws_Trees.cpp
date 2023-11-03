#include <bits/stdc++.h>
using namespace std;
map<pair<int, int>, int> mp;
int solve(vector<vector<int>> &adj, int p, int i)
{
    int ans = 0;
    for (int j = 0; j < adj[i].size(); j++)
    {
        if (adj[i][j] == p)
            continue;
        int x = 0;
        if (mp[{p, i}] > mp[{i, adj[i][j]}])
            x++;
        ans = max(ans, x + solve(adj, i, adj[i][j]));
    }
    return ans;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<vector<int>> adj(n + 1);
        mp.clear();
        for (int i = 0; i < n - 1; i++)
        {
            int x, y;
            cin >> x >> y;
            mp[{x, y}] = i;
            mp[{y, x}] = i;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        int ans = INT_MIN;
        for (int i = 0; i < adj[1].size(); i++)
        {
            ans = max(ans, solve(adj, 1, adj[1][i]));
        }
        cout << ans + 1 << endl;
    }

    return 0;
}