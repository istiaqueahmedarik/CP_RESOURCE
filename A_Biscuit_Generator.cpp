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
    int a, b, n;
    cin >> a >> b >> n;
    int x = n / a;
    cout << x * b << endl;
    return 0;
}