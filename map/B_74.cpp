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
        int l = -1, r = n;
        map<pair<int, int>, int> mp;
        pair<int, int> pos = {0, 0};
        mp[pos] = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'L')
                pos.first--;
            else if (s[i] == 'R')
                pos.first++;
            else if (s[i] == 'U')
                pos.second++;
            else
                pos.second--;
            if (mp.find(pos) != mp.end())
            {
                if (i - mp[pos] < r - l)
                {
                    l = mp[pos];
                    r = i;
                }
            }
            mp[pos] = i + 1;
        }
        if (l == -1)
            cout << -1 << endl;
        else
            cout << l + 1 << " " << r + 1 << endl;
    }
    return 0;
}