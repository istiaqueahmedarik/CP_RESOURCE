#include <bits/stdc++.h>
#define int long long
#define float double
#define endl '\n'
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);

using namespace std;
vector<int> adj_list[100005];
bool visited[100005];
bool visited1[100005];
int level[100005];
int level1[100005];
int32_t main()
{
    IOS;
    int n, e;
    cin >> n >> e;
    for (int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;
        adj_list[b].push_back(a);
        adj_list[a].push_back(b);
    }
    int r, j, k;
    cin >> r >> j >> k;
    vector<int> vl(100005);
    map<int, int> mp;
    vector<int> vl1(100005);
    map<int, int> mp1;
    queue<int> q;
    q.push(r);
    level1[r] = 0;
    while (!q.empty())
    {
        int x = q.front();
        visited1[x] = true;
        q.pop();
        for (int i = 0; i < adj_list[x].size(); i++)
        {
            if (!visited1[adj_list[x][i]])
            {
                q.push(adj_list[x][i]);
                level1[adj_list[x][i]] = level1[x] + 1;
                if (level1[adj_list[x][i]] <= k)
                {
                    vl.push_back(adj_list[x][i]);
                    mp[adj_list[x][i]] = 1;
                }
                visited1[adj_list[x][i]] = true;
            }
        }
    }
    queue<int> q1;
    q1.push(j);
    level[j] = 0;
    while (!q1.empty())
    {
        int x = q1.front();
        visited[x] = true;
        q1.pop();
        for (int i = 0; i < adj_list[x].size(); i++)
        {
            if (!visited[adj_list[x][i]])
            {
                q1.push(adj_list[x][i]);
                level[adj_list[x][i]] = level[x] + 1;
                if (level[adj_list[x][i]] <= k)
                {
                    vl1.push_back(adj_list[x][i]);
                    mp1[adj_list[x][i]] = 1;
                }
                visited[adj_list[x][i]] = true;
            }
        }
    }
    for (auto i : mp)
    {
        if (mp1[i.first] == 1)
        {
            cout << "YES" << endl;
            return 0;
        }
    }

    cout << "NO" << endl;
    return 0;
}