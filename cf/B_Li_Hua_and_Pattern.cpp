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
        int n, k;
        cin >> n >> k;
        int arr[n][n];
        int arr1[n][n];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> arr[i][j];
                arr1[i][j] = arr[i][j];
            }
        }
        int diff = 0;
        for (int i = 0; i < n / 2; i++)
        {
            for (int j = 0; j < n; j++)
            {
                {
                    arr[i][j] == arr[n - i - 1][n - j - 1] ? diff += 0 : diff += 1;
                }
            }
        }
        // for odd
        if (n % 2 != 0)
        {
            for (int i = 0; i < n / 2; i++)
            {
                arr[n / 2][i] == arr[n / 2][n - i - 1] ? diff += 0 : diff += 1;
            }
        }

        if (diff <= k)
        {
            {
                (diff - k) % 2 == 0 || n % 2 != 0 ? cout << "YES" << endl : cout << "NO" << endl;
            }
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}