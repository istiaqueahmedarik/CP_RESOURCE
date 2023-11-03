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
    int a, b, c;
    cin >> a >> b >> c;
    string ans = "No";
    for (int i = 0; i <= c; i++)
    {
        for (int j = 0; j <= c; j++)
        {
            if (i * a + j * b == c)
            {
                ans = "Yes";
                i = c + 1;
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}