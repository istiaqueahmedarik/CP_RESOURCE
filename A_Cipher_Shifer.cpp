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
        string s;
        cin >> s;
        char curr = s[0];
        string ans = "";
        for (int i = 1; i < n; i++)
        {
            if (s[i] == curr)
            {
                ans += s[i];
                if (i < n)
                {
                    curr = s[i + 1];
                    i++;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}