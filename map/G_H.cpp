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
    t = 3;
    map<char, int> coins = {{'A', 1}, {'B', 1}, {'C', 1}};
    vector<string> v;
    while (t--)
    {
        string s;
        cin >> s;
        v.push_back(s);
        char first = s[0];
        char last = s.back();
        if (s[1] == '>')
        {
            coins[first]++;
        }
        else
        {
            coins[last]++;
        }
    }

    bool ans = false;
    for (auto i : v)
    {
        char first = i[0];
        char last = i.back();
        char types = i[1];
        if (types == '>')
        {
            if (coins[first] > coins[last])
            {
                ans = true;
            }
        }
        else
        {
            if (coins[first] < coins[last])
            {
                ans = true;
            }
        }
    }

    if (!ans)
    {
        cout << "Impossible" << endl;
    }
    else
    {
        map<int, char> mp;
        for (auto i : coins)
        {
            mp[i.second] = i.first;
        }
        for (auto i : mp)
        {
            cout << i.second;
        }
    }
    return 0;
}