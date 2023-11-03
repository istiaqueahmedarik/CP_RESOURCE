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
        vector<int> b(n + 2);
        int sm = 0;
        for (int i = 0; i < n + 2; i++)
        {
            cin >> b[i];
            sm += b[i];
        }
        sort(b.begin(), b.end());
        if (2 * b[n] == sm - b[n + 1])
        {
            for (int i = 0; i < n; i++)
                cout << b[i] << " ";
            cout << endl;
            continue;
        }
        int tempSum = sm - b.back();
        int xIndex = -1;
        for (int i = 0; i < n + 1; i++)
        {
            if (tempSum - b[i] == b.back())
            {
                xIndex = i;
                break;
            }
        }
        if (xIndex == -1)
        {
            cout << -1 << endl;
            continue;
        }
        for (int i = 0; i < n + 1; i++)
        {
            if (i == xIndex)
                continue;
            cout << b[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
