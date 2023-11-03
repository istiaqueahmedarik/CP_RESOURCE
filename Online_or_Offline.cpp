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
        int n, m;
        cin >> n >> m;
        float x = n - 0.1 * n;
        if (x < m)
            cout << "ONLINE" << endl;
        else if (x > m)
            cout << "DINING" << endl;
        else
            cout << "EITHER" << endl;
    }
    return 0;
}