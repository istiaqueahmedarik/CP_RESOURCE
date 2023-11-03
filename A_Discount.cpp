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
    double percentage = (a - b) * 100.0 / a;
    cout << setprecision(6) << fixed << percentage << endl;
    return 0;
}