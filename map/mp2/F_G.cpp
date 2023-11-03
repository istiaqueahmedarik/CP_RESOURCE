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
    int n, m;
    cin >> n >> m;
    map<int, vector<pair<int, int>>> mp;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            int x;
            cin >> x;
            mp[x].push_back({i, j});
        }
    }
    int sum = 0;
    for (auto i : mp)
    {
        int key = i.first;
        vector<pair<int, int>> value = i.second;
        int size = value.size();
        if (size > 1)
        {
            for (int j = 0; j < size - 1; j++)
            {
                for (int k = j + 1; k < size; k++)
                {
                    sum += abs(value[j].first - value[k].first) + abs(value[j].second - value[k].second);
                }
            }
        }
    }
    cout << sum << endl;
    return 0;
}
