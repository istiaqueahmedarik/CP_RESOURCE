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
vector<int> fibo(50, 1);
void pre()
{
    for (int i = 2; i < 50; i++)
        fibo[i] = fibo[i - 1] + fibo[i - 2];
}
void solve()
{
    int n, k;
    cin >> n >> k;
    if (k >= 36)
        cout << 0 << endl;
    else
    {
        int ans = 0;
        int last = fibo[k - 2];
        int lastL = fibo[k - 3];
        for (int i = 0; i <= n; i++)
        {
            int temp = (n - last * i);
            if (i < temp / lastL || temp < 0)
                continue;
            ans += (temp % lastL) ? 0 : 1;
        }
        cout << ans << endl;
    }
}
auto main() -> int32_t
{
    IOS;
    pre();
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
/*
1 2 3
22 0 22 22
*/