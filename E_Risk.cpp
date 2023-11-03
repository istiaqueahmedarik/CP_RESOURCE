#include <bits/stdc++.h>
#define int long long
#define float double
#define endl '\n'
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);

using namespace std;
int t;
int32_t main()
{
    IOS;
    for (int T = 1;; T++)
    {
        int n, m;

        for (int i = 0; i < 19; i++)
        {
            cin >> m;
            if (m == -1)
                return 0;
            for (int j = 0; j < m; j++)
            {
                cin >> n;
            }
        }

        cin >> t;
        cout << "Test Set #" << T << endl;
        for (int i = 0; i < t; i++)
        {
            int a, b;
            cin >> a >> b;
        }
    }
    return 0;
}