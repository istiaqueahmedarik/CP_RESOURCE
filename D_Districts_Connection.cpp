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
    IOS;
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];
        unordered_map<int, int> ump;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            ump[arr[i]] = i + 1;
        }
        if (ump.size() >= 2)
        {
            vector<int> parents;
            int c = 0;
            for (auto i : ump)
            {
                parents.push_back(i.second);
                if (++c == 2)
                    break;
            }
            unordered_map<int, bool> visited;
            vector<pair<int, int>> ans;

            for (auto i : parents)
            {
                for (int j = 0; j < n; j++)
                {
                    if (i - 1 == j)
                        continue;
                    if (arr[j] == arr[i - 1])
                        continue;
                    if (visited[i] && visited[j + 1])
                        continue;
                    ans.push_back({i, j + 1});
                    visited[i] = visited[j + 1] = 1;
                }
            }

            cout << "YES" << endl;
            for (auto i : ans)
                cout << i.first << " " << i.second << endl;
        }
        else
            cout << "NO" << endl;
    }
    return 0;
}