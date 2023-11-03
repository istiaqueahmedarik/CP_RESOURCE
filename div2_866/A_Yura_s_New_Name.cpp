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
        int ans = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '_')
            {
                if (!i)
                    ans++;
                else
                {
                    if (s[i - 1] == '_')
                        ans++;
                }
                if (i == s.size() - 1)
                    ans++;
            }
        }
        if (s == "^")
            ans = 1;
        cout << ans << endl;
    }
    return 0;
}