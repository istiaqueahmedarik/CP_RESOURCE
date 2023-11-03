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
        string s;
        cin >> s;
        int n = s.size();
        int mn = LLONG_MAX;

        for (char i = 'a'; i <= 'z'; i++)
        {
            int x = 0, tmp = 0;
            while (1)
            {
                if (x >= n)
                    break;
                while (1)
                {
                    if (x >= n || s[x] != i)
                        break;
                    x++;
                }
                int y = x;
                while (1)
                {
                    if (y >= n || s[y] == i)
                        break;
                    y++;
                }
                tmp = max(tmp, y - x);
                x = y;
            }
            mn = min(mn, tmp);
        }
        if (mn == 0)
        {
            cout << mn << endl;
            continue;
        }

        int ans = ceil(log2(mn));
        ans += (!(mn & (mn - 1))) ? 1 : 0;
        cout << ans << endl;
    }
    return 0;
}