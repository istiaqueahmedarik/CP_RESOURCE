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
        vector<int> v(n);
        map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            mp[v[i]]++;
        }
        int MEX = 0;
        while (mp[MEX])
            MEX++;
        vector<int> zeros;
        for (int i = 0; i < n; i++)
        {
            if (v[i] == 0)
                zeros.push_back(i);
        }
        if (zeros.size() == 0)
        {
            cout << "Yes\n";
        }
        else
        {
            for (int i = 0; i < zeros.size(); i++)
            {
                if (zeros[i] == 0)
                {
                    if ()
                }
                else if (zeros[i] == zeros.size() - 1)
                {
                }
                else
                {
                }
            }
        }
    }
    return 0;
}