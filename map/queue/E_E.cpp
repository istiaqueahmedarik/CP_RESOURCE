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
        multiset<pair<int, int>> s;
        for (int i = 0; i < n; i++)
        {
            int x, y;
            cin >> x >> y;
            if (s.find({y, x}) != s.end())
            {
                s.erase(s.find({y, x}));
            }
            else
            {
                s.insert({x, y});
            }
        }
        if (s.size() == 0)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}
