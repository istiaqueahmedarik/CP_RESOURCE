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
        string s;
        cin >> n >> s;
        map<char, int> mp1, mp2;
        for (int i = 0; i < n; i++)
        {
            mp1[s[i]]++;
        }
        for (int i = 0; i < n / 2; i++)
        {
            if (s[i] == s[n - i - 1])
                mp2[s[i]]++;
        }
        int sum = 0;
        int mx = -1;
        int mx2 = -1;
        for (auto i : mp2)
        {
            sum += i.second;
            mx = max(mx, i.second);
        }
        for (auto i : mp1)
        {
            mx2 = max(mx2, i.second);
        }

        if (n & 1)
        {
            cout << -1 << endl;
            continue;
        }
        if (mx2 > n / 2)
        {
            cout << -1 << endl;
            continue;
        }

        if (mx > sum - mx)
        {
            cout << mx << endl;
            continue;
        }
        cout << sum / 2 + (sum & 1) << "\n";
    }
    return 0;
}