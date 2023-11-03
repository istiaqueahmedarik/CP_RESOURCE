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
        set<int> s, s1;
        while (n--)
        {
            int a, b;
            cin >> a >> b;
            s.insert(a);
            s1.insert(b);
        }
        cout << s.size() + s1.size() << endl;
    }
    return 0;
}