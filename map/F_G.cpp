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
    // IOS;
    map<string, string> mp;
    while (1)
    {
        string s;
        getline(cin, s);
        if (s == "")
        {
            break;
        }
        string s1 = s.substr(0, s.find(" "));
        string s2 = s.substr(s.find(" ") + 1);
        mp[s2] = s1;
    }
    string s1;
    while (cin >> s1)
    {
        if (mp[s1] == "")
        {
            cout << "eh" << endl;
        }
        else
        {
            cout << mp[s1] << endl;
        }
    }
    return 0;
}