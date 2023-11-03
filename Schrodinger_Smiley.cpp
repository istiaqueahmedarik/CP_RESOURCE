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
        int i = 0, ans = 0;
        bool flag = true;
        int temp = 0;
        while (i < n)
        {
            if (s[i] == ':')
            {
                if (!flag && temp)
                {
                    ans++;
                    temp = 0;
                }
                if (flag)
                {
                    temp = 0;
                    flag = false;
                }
                i++;
            }
            else if (s[i] == ')')
            {
                temp++;
                i++;
            }
            else
            {
                flag = true;
                i++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
