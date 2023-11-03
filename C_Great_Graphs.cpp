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
        vector<int> arr(n + 1), pre(n + 1);
        for (int i = 1; i <= n; i++)
        {
            cin >> arr[i];
        }
        sort(arr.begin(), arr.end());
        for (int i = 1; i <= n; i++)
        {
            if (i > 1)
                pre[i] = pre[i - 1] + arr[i];
            else
                pre[i] = arr[i];
        }
        if (n == 1)
            cout << 0 << endl;
        else
        {
            int ans = 0;
            for (int i = 3; i <= n; i++)
            {
                ans += pre[i - 2] - ((i - 2) * arr[i]);
            }
            cout << ans << endl;
        }
    }
    return 0;
}