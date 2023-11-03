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
    int a, b;
    cin >> a >> b;
    if (a >= b)
        cout << 0 << endl;
    else
        cout << b - a + 1 << endl;
    return 0;
}