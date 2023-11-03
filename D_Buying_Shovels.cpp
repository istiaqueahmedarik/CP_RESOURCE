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
        if (n <= k)
            cout << 1 << endl;
        else
        {
            int mx = LLONG_MAX;
            for (int i = 1; i * i <= n && i <= k; i++)
            {
                if (n % i == 0)
                {
                    mx = min(mx, n / i);
                    if (n / i <= k)
                        mx = min(mx, i);
                }
            }
            cout << mx << endl;
        }
    }
    return 0;
}