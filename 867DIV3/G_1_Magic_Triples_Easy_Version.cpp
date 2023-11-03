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
        int a[n];
        map<int, int> mp;
        int mx = -1;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            mp[a[i]]++;
            mx = max(mx, a[i]);
        }
        int c = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 1;; j++)
            {
                if (mp[a[i] * j] && mp[a[i] * j * j])
                    c++;
                if (a[i] * j * j > mx)
                    break;
            }
        }
        cout << c << endl;
    }
    return 0;
}