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
    int n;
    cin >> n;
    char ans[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                if (i != n / 2)
                    ans[i][j] = 92;
                else
                    ans[i][j] = 'X';
            }
            else if (i == n - j - 1)
            {
                if (i != n / 2)
                {
                    ans[i][j] = '/';
                }
            }
            else
            {
                ans[i][j] = '*';
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << ans[i][j];
        }
        cout << endl;
    }
    return 0;
}