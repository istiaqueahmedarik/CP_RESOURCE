#include <bits/stdc++.h>
#define int long long
#define float double
#define endl '\n'
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);

using namespace std;
map<int, int> cnt;
map<int, bool> visited;
map<int, vector<int>> adjList;
void dfs(int node)
{
    // cout << node << endl;

    for (auto i : adjList[node])
    {
        if (!visited[i])
        {
            cnt[i]--;
            if (cnt[i] <= 0)
                visited[i] = true;
            dfs(i);
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
        cnt.clear();
        visited.clear();
        adjList.clear();
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            cnt[arr[i]]++;
        }
        sort(arr, arr + n, greater<int>());
        for (int i = 0; i < n - 1; i++)
        {
            if (arr[i] != arr[i + 1] && arr[i] - 1 == arr[i + 1])
                adjList[arr[i]].push_back(arr[i + 1]);
        }
        int ans = 0;
        // for (auto i : adjList)
        // {
        //     cout << i.first << "-->";
        //     for (auto j : i.second)
        //     {
        //         cout << j << " ";
        //     }
        //     cout << endl;
        // }
        for (int i = 0; i < n; i++)
        {
            if (!visited[arr[i]])
            {
                cnt[arr[i]]--;
                if (cnt[arr[i]] <= 0)
                    visited[arr[i]] = true;
                dfs(arr[i]);
                ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}