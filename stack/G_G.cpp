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
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    stack<int> s;
    for (int i = n - 1; i >= 0; i--)
    {
        if (s.empty())
        {
            s.push(v[i]);
        }
        else
        {
            if (s.top() >= v[i])
            {
                s.push(v[i]);
            }
        }
    }
    int sm = 0;
    while (!s.empty())
    {
        sm += s.top();
        s.pop();
    }
    cout << sm << endl;
    return 0;
}