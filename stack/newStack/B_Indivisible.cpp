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
        int sm = n * (n - 1) / 2;
        if (n == 1)
        {
            cout << 1 << endl;
        }
        else if (sm % (n) == 0)
        {
            cout << -1 << endl;
        }
        else
        {
            vector<int> ans(n + 1);
            for (int i = 2; i <= n; i += 2)
            {
                ans[i - 1] = i;
            }
            for (int i = 1; i <= n; i += 2)
            {
                ans[i + 1] = i;
            }
            for (int i = 1; i <= n; i++)
            {
                cout << ans[i] << " ";
            }

            cout << endl;
        }
    }
    return 0;
}
