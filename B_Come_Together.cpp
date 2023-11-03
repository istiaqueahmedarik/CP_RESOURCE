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
        int xa, ya;
        cin >> xa >> ya;
        int xb, yb;
        cin >> xb >> yb;
        int xc, yc;
        cin >> xc >> yc;
        int init = 1;
        if ((xb < xa && xc < xa))
        {
            init += min(abs(xb - xa), abs(xc - xa));
        }
        else if (xb > xa && xc > xa)
        {
            init += min(abs(xb - xa), abs(xc - xa));
        }
        if (yb < ya and yc < ya)
        {
            init += min(abs(yb - ya), abs(yc - ya));
        }
        else if (yb > ya and yc > ya)
        {
            init += min(abs(yb - ya), abs(yc - ya));
        }
        cout << init << endl;
    }
    return 0;
}
