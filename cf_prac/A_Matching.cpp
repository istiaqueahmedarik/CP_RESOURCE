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
        if (s[0] == '0')
        {
            cout << 0 << endl;
        }
        else
        {
            int leading_ques = s[0] == '?' ? 1 : 0;
            int ans = 1;
            for (int i = 1; i < s.size(); i++)
            {
                if (s[i] == '?')
                {
                    ans *= 10;
                }
            }
            if (leading_ques)
                ans *= leading_ques * 9;
            cout << ans << endl;
        }
    }
    return 0;
}