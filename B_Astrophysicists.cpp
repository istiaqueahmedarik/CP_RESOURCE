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
        int n, k, g;
        cin >> n >> k >> g;
        int Total = k * g;
        int gCeil = (g + 1) / 2;
        int x = (gCeil - 1) * n;
        int remaining = g - x;
        int TP = Total + remaining - 1;
        int cost = TP / g;
        cout << min(Total, Total - cost * g) << endl;
    }
    return 0;
}