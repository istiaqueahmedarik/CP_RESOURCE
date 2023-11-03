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
        string a, b, c;
        cin >> a >> b >> c;
        int k = 0;
        if (a[0] <= b[0])
            k = b[0] - a[0];
        else
        {
            k = 26 - a[0];
            k += b[0];
        }
        for (int i = 0; i < c.size(); i++)
        {
            c[i] = (c[i] - 'a' + k) % 26 + 'a';
        }
        cout << c << endl;
    }
    return 0;
}