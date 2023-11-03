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
        int l, r, k;
        cin >> l >> r >> k;
        if (k == 0)
        {
            if (l != r || l == 1)
                cout << "NO" << endl;
            else
                cout << "YES" << endl;
        }
        else
        {
            int length = (r - l + 1);
            int pr = length / 2;
            if (l & 1 && r & 1)
                pr++;
            if (pr <= k)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    }
    return 0;
}