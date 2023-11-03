#include <bits/stdc++.h>
#define int long long
#define float double
#define endl '\n'
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);

using namespace std;
bool palin(string &s)
{
    for (int i = 0; i <= s.size() / 2; i++)
    {
        if (s[i] != s[s.size() - i - 1])
            return false;
    }
    return true;
}
int32_t main()
{
    IOS;
    int t;
    cin >> t;
    while (t--)
    {
        int a, b;
        string s;
        cin >> a >> b >> s;
        bool flag = true;
        for (int i = 0; i < s.size(); i++)
            if (s[i] == '?')
                s[i] = s[s.size() - i - 1];
        int cA = count(s.begin(), s.end(), '0');
        int cB = count(s.begin(), s.end(), '1');
        a -= cA;
        b -= cB;
        int n = s.size();
        for (int i = 0; i <= n / 2; i++)
        {
            if (i == n - i - 1)
            {
                if (s[i] == '?')
                {
                    if (a)
                        s[i] = '0', a--;
                    else
                        s[i] = '1', b--;
                }
            }
            else
            {
                if (s[i] == '?')
                {
                    if (a > 1)
                        s[i] = s[n - i - 1] = '0', a -= 2;
                    else if (b > 1)
                        s[i] = s[n - i - 1] = '1', b -= 2;
                }
            }
        }
        if (a > 0 || b > 0 || !palin(s))
            flag = false;
        if (flag)
            cout << s << endl;
        else
            cout << -1 << endl;
    }
    return 0;
}