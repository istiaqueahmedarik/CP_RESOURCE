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
        int n, k;
        cin >> n >> k;
        map<int, pair<int, int>> mp;
        map<int, int> presence;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            if (presence[x])
            {
                mp[x].second = i;
            }
            else
            {
                mp[x].first = i;
                mp[x].second = i;
                presence[x] = 1;
            }
        }
        for (int i = 0; i < k; i++)
        {
            int a, b;
            cin >> a >> b;
            bool c1 = presence[a];
            bool c2 = presence[b];
            if (!c1 || !c2 || mp[a].first > mp[b].second)
            {
                cout << "NO" << endl;
            }
            else
            {
                cout << "YES" << endl;
            }
        }
    }
    return 0;
}