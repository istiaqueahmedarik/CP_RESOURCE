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
        vector<int> b(n * m);
        for (int i = 0; i < n * m; i++)
        {
            cin >> b[i];
        }
        sort(b.rbegin(), b.rend());
        int small_1 = b[b.size() - 1];
        int small_2 = b[b.size() - 2];
        int max_1 = b[0];
        int max_2 = b[1];
        int temp = (n - 1) * (max_1 - small_2) + (n) * (m - 1) * (max_1 - small_1);
        int ans = (n - 1) * (max_2 - small_1) + (n) * (m - 1) * (max_1 - small_1);
        swap(n, m);
        int temp1 = (n - 1) * (max_1 - small_2) + (n) * (m - 1) * (max_1 - small_1);
        int ans2 = (n - 1) * (max_2 - small_1) + (n) * (m - 1) * (max_1 - small_1);
        int x = max(temp, temp1);
        int y = max(ans, ans2);
        cout << max(x, y) << endl;
    }
    return 0;
}
