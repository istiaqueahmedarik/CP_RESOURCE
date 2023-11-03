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
        if (m > n)
        {
            cout << "NO" << endl;
        }
        else
        {
            if (n == m)
                cout << "YES" << endl;
            else
            {
                queue<int> q;
                int flag = 0;
                q.push(n);
                while (!q.empty())
                {
                    int x = q.front();
                    if (x == m || 2 * x == m)
                    {
                        cout << "YES" << endl;
                        flag = 1;
                        break;
                    }
                    q.pop();
                    if (x % 3)
                        break;
                    x = x / 3;
                    if (x == m || 2 * x == m)
                    {
                        cout << "YES" << endl;
                        flag = 1;
                        break;
                    }
                    q.push(x);
                    q.push(2 * x);
                }
                if (!flag)
                    cout << "NO" << endl;
            }
        }
    }
    return 0;
}