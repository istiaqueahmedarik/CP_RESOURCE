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
    int cs = 1;
    while (t--)
    {
        cout << "Case " << cs++ << ":\n";

        int p;
        cin >> p;
        stack<int> s;
        stack<int> m;
        int mx = -1;
        while (p--)
        {
            char c;
            cin >> c;
            if (c == 'A')
            {
                int n;
                cin >> n;
                s.push(n);
                mx = max(mx, n);
                m.push(mx);
            }
            else if (c == 'Q')
            {
                if (s.empty())
                {
                    cout << "Empty\n";
                }
                else
                {
                    cout << m.top() << endl;
                }
            }
            else if (c == 'R')
            {
                if (!s.empty())
                {
                    s.pop();
                    m.pop();
                    if (m.empty())
                    {
                        mx = -1;
                    }
                    else
                    {
                        mx = m.top();
                    }
                }
            }
        }
    }
    return 0;
}