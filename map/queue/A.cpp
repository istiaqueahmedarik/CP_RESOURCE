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
    int cs = 0;
    while (t--)
    {
        int n;
        cin >> n;

        cout << "Case " << ++cs << ":" << endl;
        stack<int> s, mx;
        while (n--)
        {
            char c;
            cin >> c;
            if (c == 'A')
            {
                int x;
                cin >> x;
                s.push(x);
                if (mx.empty())
                {
                    mx.push(x);
                }
                else
                {
                    mx.push(max(x, mx.top()));
                }
            }
            else if (c == 'R')
            {
                if (!s.empty() && !mx.empty())
                    s.pop(), mx.pop();
            }
            else if (c == 'Q')
            {
                if (!mx.empty())
                {
                    cout << mx.top() << endl;
                }
                else
                    cout << "Empty" << endl;
            }
        }
    }
    return 0;
}