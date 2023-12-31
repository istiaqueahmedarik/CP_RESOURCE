#include <bits/stdc++.h>
using namespace std;

void dfs(int cur, vector<bool> &vis, vector<vector<int>> &adjList, stack<int> &s)
{
    vis[cur] = 1;
    for (auto i : adjList[cur])
    {
        if (!vis[i])
            dfs(i, vis, adjList, s);
    }
    s.push(cur);
}

vector<stack<int>> Tropo(vector<vector<int>> adjList)
{
    vector<bool> vis(adjList.size(), 0);
    vector<stack<int>> ans;
    for (int i = 0; i < adjList.size(); i++)
    {
        stack<int> s;
        if (!vis[i])
        {
            dfs(i, vis, adjList, s);
        }
        if (s.size())
            ans.push_back(s);
    }
    return ans;
}
int main()
{
    int n, e;
    cin >> n >> e;
    vector<vector<int>> adjList(n + 1);
    for (int i = 0; i < e; i++)
    {
        char u, v;
        cin >> u >> v;
        int x = u - 'A';
        int y = v - 'A';
        adjList[y].push_back(x);
    }
    vector<stack<int>> ans = Tropo(adjList);
    for (auto i : ans)
    {
        vector<char> temp;
        while (!i.empty())
        {
            temp.push_back((char)(i.top() + 'A'));
            i.pop();
        }
        reverse(temp.begin(), temp.end());
        for (auto j : temp)
            cout << j << " ";
    }
}