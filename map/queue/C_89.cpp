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
    queue<int> q;
    while (t--)
    {
        int x;
        cin >> x;
        if (x == 1)
        {
            int y;
            cin >> y;
            q.push(y);
        }
        else if (x == 2)
        {
            if (!q.empty())
                q.pop();
        }
        else
        {
            if (q.empty())
                cout << "Empty!" << endl;
            else
                cout << q.front() << endl;
        }
    }
    return 0;
}