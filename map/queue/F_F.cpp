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
        int n, m, k;
        cin >> n >> m >> k;
        set<int> s;
        for (int i = 0; i < m; i++)
        {
            int x, y;
            cin >> x >> y;
            s.insert(x);
        }
        int flag = 1;
        for (int i = 0; i < k; i++)
        {
            int x, y;
            cin >> x >> y;
            if (!s.count(x))
            {
                flag = 0;
            }
        }
        if (flag)
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
    return 0;
}