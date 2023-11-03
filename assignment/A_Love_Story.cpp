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
        string main = "codeforces";
        int diff = 0;
        for (int i = 0; i < main.size(); i++)
        {
            if (s[i] != main[i])
            {
                diff++;
            }
        }
        diff += s.size() - main.size();
        cout << diff << endl;
    }
    return 0;
}