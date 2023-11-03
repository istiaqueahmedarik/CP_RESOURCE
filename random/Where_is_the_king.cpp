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
    // IOS;
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> pre(n + 1, 0);
        for (int i = 1; i <= n; i++)
        {
            int x;
            cin >> x;
            pre[i] = pre[i - 1] + x;
        }
        bool flag = 1;
        for (int i = 0; i < n; i++)
        {
            if (pre[i] == pre[n] - pre[i + 1])
            {
                cout << i << endl;
                flag = false;
                break;
            }
        }
        if (flag)
            cout << -1 << endl;
    }
    return 0;
}