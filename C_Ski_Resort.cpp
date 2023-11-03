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
        int n, k, q;
        cin >> n >> k >> q;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
            cin >> v[i];
        int i = 0, j = 0;
        vector<int> sec;
        while (j <= n - 1)
        {
            if (v[j] <= q)
            {
                j++;
            }
            else
            {
                sec.push_back(j - i);
                i = j;
                i++;
                j++;
            }
        }
        sec.push_back(j - i);
        int ans = 0;
        for (auto i : sec)
        {
            int temp = i - k + 1;
            if (i >= k)
                ans += (temp * (temp + 1)) / (2);
        }
        cout << ans << endl;
    }
    return 0;
}