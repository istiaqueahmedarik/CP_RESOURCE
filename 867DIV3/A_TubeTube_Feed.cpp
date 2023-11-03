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
        int n, t;
        cin >> n >> t;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        int b[n];
        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
        }
        int j = 0;
        int mx = -1;
        int ans = -1;
        for (int i = t; i >= 0; i--)
        {
            if (j == n)
                break;
            if (a[j] <= i)
            {
                if (b[j] > mx)
                {
                    mx = b[j];
                    ans = j;
                }

                // cout << i << " " << b[j] << endl;
            }
            j++;
        }
        if (ans != -1)
            cout << ans + 1 << endl;
        else
        {
            cout << -1 << endl;
        }
        // cout << endl;
    }
    return 0;
}