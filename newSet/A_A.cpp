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
        set<string> s;
        int n;
        cin >> n;
        while (n--)
        {
            string st;
            cin >> st;
            s.insert(st);
        }
        cout << s.size() << endl;
    }
    return 0;
}