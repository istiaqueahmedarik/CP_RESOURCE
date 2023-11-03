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
        map<int, int> mp;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            mp[arr[i]]++;
        }
        int ans = 0;
        for (int i = 2; i <= 2 * n; i++)
        {
            int c = 0;
            for (auto j : mp)
            {
                if (mp[i - j.first] && i - j.first > 0)
                {
                    c += min(j.second, mp[i - j.first]);
                }
            }
            c /= 2;
            ans = max(ans, c);
        }
        cout << ans << endl;
    }
    return 0;
}