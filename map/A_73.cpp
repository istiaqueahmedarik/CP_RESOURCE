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
    multimap<string, int> mp;
    while (t--)
    {
        int type;
        cin >> type;
        if (type == 0)
        {
            string s;
            int x;
            cin >> s >> x;
            mp.insert({s, x});
        }
        else if (type == 1)
        {
            string s;
            cin >> s;
            for (auto i = mp.lower_bound(s); i != mp.upper_bound(s); i++)
            {
                cout << i->second << endl;
            }
        }
        else if (type == 2)
        {
            string s;
            cin >> s;
            mp.erase(s);
        }
        else
        {
            string l, r;
            cin >> l >> r;
            for (auto i : mp)
            {
                if (i.first >= l && i.first <= r)
                {
                    cout << i.first << " " << i.second << endl;
                }
            }
        }
    }
    return 0;
}