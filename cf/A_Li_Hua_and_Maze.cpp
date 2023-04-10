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
        int n, m;
        cin >> n >> m;
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int temp;
        if ((x1 == 1 && y1 == 1) || (x2 == 1 && y2 == 1) || (x1 == n && y1 == m) || (x2 == n && y2 == m) || (x1 == 1 && y1 == m) || (x2 == 1 && y2 == m) || (x1 == n && y1 == 1) || (x2 == n && y2 == 1))
        {
            temp = 2;
        }
        else if (x1 == 1 || x1 == n || y1 == 1 || y1 == m || x2 == 1 || x2 == n || y2 == 1 || y2 == m)
        {
            temp = 3;
        }
        else
        {
            temp = 4;
        }
        cout << min({temp, n, m}) << endl;
    }
    return 0;
}