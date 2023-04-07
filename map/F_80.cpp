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
    int n, q;
    cin >> n >> q;
    map<int, int> mp;
    while (q--)
    {
        int x;
        cin >> x;
        if (x == 1)
        {
            int y;
            cin >> y;
            mp[y] = -1;
        }
        else
        {
            int y;
            cin >> y;
            if (mp.lower_bound(y) == mp.end())
            {
                cout << -1 << endl;
            }
            else
            {
                cout << mp.lower_bound(y)->first << endl;
            }
        }
    }
    return 0;
}