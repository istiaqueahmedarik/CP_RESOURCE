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
        int x, y, a, b;
        cin >> x >> y >> a >> b;
        if (a == x && b == y)
        {
            cout << 0 << endl;
            continue;
        }
        int ans = ((a + b) % 2 == (x + y) % 2) ? 2 : 1;
        cout << ans << endl;
    }
    return 0;
}