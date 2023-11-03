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
        int n, d, h;
        cin >> n >> d >> h;
        vector<int> he(n);
        for (int i = 0; i < n; i++)
            cin >> he[i];
        set<int> s;
        for (auto i : he)
        {
            for (int j = i + 1; j <= i + h; j++)
            {
                s.insert(j);
            }
        }
        float x = n * h - s.size();
        cout << x << endl;
        float each = d / h;
        float ans = n * ((h * d) / 2.0);
        cout << ans - x * (each / 2.0) << setprecision(10) << fixed << endl;
    }
    return 0;
}
/*
    base d and height h

*/