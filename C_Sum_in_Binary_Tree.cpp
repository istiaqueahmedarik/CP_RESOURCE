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
        int sm = 0;
        while (1)
        {
            if (!n)
                break;
            sm += n;
            n >>= 1;
        }
        cout << sm << endl;
    }
    return 0;
}
