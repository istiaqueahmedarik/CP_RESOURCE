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
    bool flag = false;
    while ((cin >> t))
    {
        if (flag)
            cout << endl;
        flag = true;
        map<string, vector<string>> m;
        map<string, int> nodes;
        while (t--)
        {
            string a, b;
            cin >> a >> b;
            m[a].push_back(b);
            m[b].push_back(a);
            nodes[a]++;
            nodes[b]++;
        }
        string x, y;
        cin >> x >> y;
        map<string, string> parent;
        map<string, bool> visited;
        queue<string> q;
        q.push(x);
        visited[x] = true;
        while (!q.empty())
        {
            string prnt = q.front();
            visited[prnt] = true;
            q.pop();
            for (auto i : m[prnt])
            {
                if (!visited[i])
                {
                    parent[i] = prnt;
                    q.push(i);
                }
            }
        }
        vector<pair<string, string>> ans;
        if (!nodes[x] || !nodes[y])
        {
            cout << "No route" << endl;

            continue;
        }
        if (visited[y] == false)
        {
            cout << "No route" << endl;

            continue;
        }
        while (1)
        {
            ans.push_back({parent[y], y});
            if (parent[y] == x)
                break;
            y = parent[y];
        }
        reverse(ans.begin(), ans.end());
        for (auto i : ans)
        {
            cout << i.first << " " << i.second << endl;
        }
    }
    return 0;
}