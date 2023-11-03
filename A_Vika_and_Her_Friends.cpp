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
        pair<int, int> start;
        cin >> start.first >> start.second;
        bool flag = true;
        while (k--)
        {
            int a, b;
            cin >> a >> b;
            if (abs(start.first - a) % 2 == abs(start.second - b) % 2)
            {
                flag = false;
            }
        }
        if (flag)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}