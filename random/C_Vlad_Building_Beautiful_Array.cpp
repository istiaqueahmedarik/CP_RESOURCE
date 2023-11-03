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
        vector<int> v(n);
        int od = 0, ev = 0;
        int mn = LLONG_MAX;
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            if (v[i] & 1)
            {
                od++;
                mn = min(v[i], mn);
            }
            else
                ev++;
        }

        if (od == n || ev == n)
        {
            cout << "YES" << endl;
            continue;
        }
        bool flag = true;
        for (int i = 0; i < n; i++)
        {
            if (v[i] & 1)
                continue;
            if (v[i] <= mn)
            {
                flag = false;
                break;
            }
        }
        if (flag)
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
