#include <bits/stdc++.h>
#define int long long
#define float double
#define endl '\n'
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);

using namespace std;
// right shift
void cyclic_shift(string &s)
{
    int n = s.size();
    char temp = s[n - 1];
    for (int i = n - 1; i > 0; i--)
    {
        s[i] = s[i - 1];
    }
    s[0] = temp;
}
int32_t main()
{
    IOS;
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int c = 0;
        for (int i = 0; i < s.size(); i++)
            if (s[i] == '1')
                c++;
        int ans = 0;
        if (c == s.size())
        {
            ans = s.size() * s.size();
        }
        else
        {
            int c1 = 0;
            int temp = 0;
            int i = 0, j = 0;
            while (1)
            {
                if (s[i % s.size()] == '0')
                {
                    c1 = max(c1, temp);
                    temp = 0;
                }
                else
                {
                    temp++;
                }
                c1 = max(c1, temp);
                i++, j++;
                if (j >= s.size() && s[i % s.size()] == '0')
                    break;
            }
            c1 = max(c1, temp);
            c1++;
            ans = c1 * c1;
            ans /= 4;
        }
        cout << ans << endl;
    }
    return 0;
}