#include <bits/stdc++.h>
using namespace std;
#define int long long
#define float double
#define endl '\n'
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
// decltype
const float pi = 3.141592653589793238462643383279502884197;
const int MOD = 1e9 + 7, dx[] = {1, 0, -1, 0, 1, -1, -1, 1}, dy[] = {0, 1, 0, -1, 1, 1, -1, -1};
void solve()
{
    int n, k;
    cin >> n >> k;
    int ans = 0;
    int total = n / k;
    for (int i = 0; i < 10; i++)
    {
        int times = i + 1;
        int temp = (k * times);
        temp %= 10;
        int last = total % 10;
        if (last >= times)
            ans += (total / 10 + 1) * temp;
        else
            ans += (total / 10) * temp;
    }
    cout << ans << endl;
}
auto main() -> int32_t
{
    IOS;
    int t, cs = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}