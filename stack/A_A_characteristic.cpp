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
        if (k == 0 && n == 2)
        {
            cout << "YES" << endl;
            for (int i = 0; i < n; i++)
            {
                cout << 1 * pow(-1, i) << " ";
            }
            cout << endl;
        }
        else if (k == 0 && n > 2)
        {
            cout << "NO" << endl;
        }
        else
        {

            int flag = -1;
            for (int i = 1; i <= n; i++)
            {
                int age = (n - i) * (n - i - 1) / 2;
                int neg = i * (i - 1) / 2;
                if (neg + age == k)
                {
                    flag = i;
                    break;
                }
            }
            if (flag == -1)
            {
                cout << "NO" << endl;
            }
            else
            {
                cout << "YES" << endl;
                for (int i = 1; i <= flag; i++)
                {
                    cout << -1 << " ";
                }
                for (int i = 1; i <= n - flag; i++)
                {
                    cout << 1 << " ";
                }
                cout << endl;
            }
        }
    }
    return 0;
}
