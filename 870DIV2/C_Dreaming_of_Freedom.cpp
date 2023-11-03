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
        int a, b;
        cin >> a >> b;
        if (a == 1 || b == 1)
        {
            cout << "YES" << endl;
            continue;
        }
        if (a <= b)
        {
            cout << "NO" << endl;
            continue;
        }
        while (1)
        {
            if (b == 1)
            {
                cout << "YES" << endl;
                break;
            }
            if (b == 0)
            {
                cout << "NO" << endl;
                break;
            }
            b = a % b;
        }
    }
    return 0;
}