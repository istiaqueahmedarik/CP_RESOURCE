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
        map<int, int> mp;
        for (int i = 0; i < k; i++)
        {
            int a, b;
            cin >> a >> b;
            mp[a]++;
            mp[b]++;
        }
        map<int, int> mp2;
        for (auto i : mp)
        {
            if (i.second != 1)
            {
                mp2[i.second]++;
            }
        }
        int a = 0, b = 0;
        for (auto i : mp2)
        {
            a = i.second == 1 ? i.first : a;
            b = i.second != 1 ? i.first : b;
        }
        if (a == 0 || b == 0)
        {
            cout << a + b << " " << a + b - 1 << endl;
            continue;
        }
        cout << a << " " << b - 1 << endl;
    }
    return 0;
}