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
        int n, k;
        cin >> n >> k;
        map<int, bool> mp;
        vector<string> v;
        for (int i = 0; i < n; i++)
        {
            string s;
            cin >> s;
            v.push_back(s);
            mp[i] = true;
        }
        string Mn = v[0];
        for (int i = 0; i < k; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (Mn[i] != v[j][i])
                {
                    mp[j] = false;
                }
            }
        }
        int c = 0;
        for (auto i : mp)
        {
            if (i.second == true)
            {
                c++;
            }
        }
        cout << c << endl;
    }
    return 0;
}