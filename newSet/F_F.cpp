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
        set<int> s;
        while (n--)
        {
            int x;
            cin >> x;
            if (x % 2 == 0)
            {
                s.insert(x);
            }
        }
        int c = 0;
        while (!s.empty())
        {
            int x = *s.rbegin();
            s.erase(x);
            x = x / 2;
            if (x % 2 == 0)
            {
                s.insert(x);
            }
            c++;
        }
        cout << c << endl;
    }
    return 0;
}