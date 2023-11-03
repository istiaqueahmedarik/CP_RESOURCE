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
        int e = 0, od = 0;
        int mx = LLONG_MIN;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            if (i & 1 && x > 0)
                od += x;
            else if (x > 0)
                e += x;
            mx = max(x, mx);
        }
        int ans = max(e, od);
        if (ans)
            cout << ans << endl;
        else
            cout << mx << endl;
    }
    return 0;
}