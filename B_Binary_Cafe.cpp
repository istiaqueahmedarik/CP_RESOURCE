#include <bits/stdc++.h>
#define int long long
#define float double
#define endl '\n'
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);

using namespace std;
int POW(int x, int n)
{
    int result = 1;
    for (;;)
    {
        if (n & 1)
            result *= x;
        n >>= 1;
        if (!n)
            break;
        x *= x;
    }

    return result;
}
int32_t main()
{
    IOS;
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int div = log2(n);
        if (k > div)
            cout << n + 1 << endl;
        else
            cout << POW(2, k) << endl;
    }
    return 0;
}