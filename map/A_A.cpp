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
    map<string, int> mp;
    while (t--)
    {
        int type;
        cin >> type;
        string s;
        cin >> s;

        if (type == 1)
        {
            int y;
            cin >> y;
            mp[s] += y;
        }
        else if (type == 2)
        {
            mp.erase(s);
        }
        else
        {
            cout << mp[s] << endl;
        }
    }
    return 0;
}