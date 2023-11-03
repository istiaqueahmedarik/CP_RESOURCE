#include <bits/stdc++.h>
#define int long long
#define float double
#define endl '\n'
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);

using namespace std;
void wrong()
{
}
int32_t main()
{
    IOS;
    int t;
    cin >> t;
    while (t--)
    {
        int n, k, x;
        cin >> n >> k >> x;
        if (x != 1)
        {
            cout << "YES" << endl;
            cout << n << endl;
            for (int i = 0; i < n; i++)
            {
                cout << 1 << " ";
            }
            cout << endl;
        }
        else if (n == 1 || k <= 1)
        {
            cout << "NO" << endl;
        }
        else
        {
            if (n & 1)
            {
                if (k >= 3)
                {
                    cout << "YES" << endl;
                    int total = (n - 3) / 2 + 1;
                    cout << total << endl;
                    for (int i = 0; i < total - 1; i++)
                    {
                        cout << 2 << " ";
                    }
                    cout << 3 << endl;
                }
                else
                    cout << "NO" << endl;
            }
            else
            {
                if (k >= 2)
                {
                    cout << "YES" << endl;
                    int total = n / 2;
                    cout << total << endl;
                    for (int i = 0; i < total; i++)
                    {
                        cout << 2 << " ";
                    }
                    cout << endl;
                }
                else
                    cout << "NO" << endl;
            }
        }
    }
    return 0;
}