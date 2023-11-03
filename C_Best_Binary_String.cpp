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
        char temp = '0';
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '?')
            {
                s[i] = temp;
            }
            else
            {
                temp = s[i];
            }
        }
        cout << s << endl;
    }
    return 0;
}
