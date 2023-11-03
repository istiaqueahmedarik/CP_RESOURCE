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
        vector<int> a(n);
        for (auto &i : a)
            cin >> i;
        vector<int> b(n);
        for (auto &i : b)
            cin >> i;
        vector<pair<int, int>> ans(n);
        for (int i = 0; i < n; i++)
        {
            ans[i].first = b[lower_bound(b.begin(), b.end(), a[i]) - b.begin()] - a[i];
        }
        int temp = n;
        for (int i = n - 1; i >= 0; i--)
        {
            int x = lower_bound(b.begin(), b.begin() + temp, a[i]) - b.begin();
            ans[i].second = b[temp - 1] - a[i];
            if (x == i)
                temp = i;
        }
        for (auto i : ans)
        {
            cout << i.first << " ";
        }
        cout << endl;
        for (auto i : ans)
        {
            cout << i.second << " ";
        }
        cout << endl;
    }
    return 0;
}