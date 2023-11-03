#include <bits/stdc++.h>
#define int long long
#define float double
#define endl '\n'
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);

using namespace std;
bool prime[1005];
void seive()
{
    for (int i = 0; i <= 1003; i++)
        prime[i] = true;
    prime[0] = prime[1] = false;
    for (int i = 2; i <= 1003; i++)
    {
        if (prime[i] == true)
        {
            for (int j = i * i; j <= 1003; j += i)
                prime[j] = false;
        }
    }
}
int32_t main()
{
    IOS;
    seive();
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        if (prime[n])
        {
            int p = 1;
            int ans[n][m];
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j += 2)
                {
                    ans[i][j] = p;
                    p++;
                }
            }
            for (int i = 0; i < n; i++)
            {
                for (int j = 1; j < m; j += 2)
                {
                    ans[i][j] = p;
                    p++;
                }
            }
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    cout << ans[i][j] << " ";
                }
                cout << endl;
            }
        }
        else if (prime[m])
        {
            int p = 1;
            int ans[n][m];
            for (int i = 0; i < n; i += 2)
            {
                for (int j = 0; j < m; j++)
                {
                    ans[i][j] = p;
                    p++;
                }
            }
            for (int i = 1; i < n; i += 2)
            {
                for (int j = 0; j < m; j++)
                {
                    ans[i][j] = p;
                    p++;
                }
            }
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    cout << ans[i][j] << " ";
                }
                cout << endl;
            }
        }
        else
        {
            int p = 1;
            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= m; j++)
                {
                    cout << p << " ";
                    p++;
                }
                cout << endl;
            }
        }
    }
    return 0;
}