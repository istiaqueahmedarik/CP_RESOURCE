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
    map<string, string> mp;  // old vs now
    map<string, string> mp1; // now vs old
    while (t--)
    {
        string s, s1;
        cin >> s >> s1;
        if (mp1[s] == "")
        {
            mp[s] = s1;
            mp1[s1] = s;
        }
        else
        {
            mp[mp1[s]] = s1;
            mp1[s1] = mp1[s];
        }
    }
    cout << mp.size() << endl;
    for (auto i : mp)
    {
        cout << i.first << " " << i.second << endl;
    }

    return 0;
}