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
        int n, m;
        cin >> n >> m;
        int x1, y1, x2, y2, x3, y3, ansX, ansY;
        // middle
        cout << "? " << n / 2 << " " << m / 2 << endl;
        cin >> x1 >> y1;
        // middle + 1
        cout << "? " << n / 2 + 1 << " " << m / 2 << endl;
        cin >> x2 >> y2;
        // middle -1
        cout << "? " << n / 2 << " " << m / 2 + 1 << endl;
        cin >> x3 >> y3;
        int sumX = x1 + x2 + x3;
        if ((n + m) - 1 >= sumX)
        {
            ansX = n - x1;
            ansY = m - y1;
        }
        else if (n % 2 != 0 && 2 * sumX >= 2 * (m + n) - 1)
        {
            ansX = n - x2;
            ansY = m - y2;
        }
        else if (n % 2 == 0 && sumX >= (m + n))
        {

            ansX = n - x2;
            ansY = m - y2;
        }
        else
        {
            ansX = n - x3;
            ansY = m - y3;
        }
        cout << "! " << ansX << " " << ansY << endl;
    }
    return 0;
}