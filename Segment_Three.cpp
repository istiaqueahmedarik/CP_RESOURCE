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
    int n;
    cin >> n;
    vector<int> arr(n);
    int zero = 0, one = 0, two = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (arr[i] % 3 == 0)
            zero++;
        else if (arr[i] % 3 == 1)
            one++;
        else
            two++;
    }
    int ans = 0;
    while (zero > n / 3)
    {
        zero--;
        one++;
        ans++;
    }
    while (one > n / 3)
    {
        one--;
        two++;
        ans++;
    }
    while (two > n / 3)
    {
        two--;
        ans++;
    }
    cout << ans << endl;
}

auto main() -> int32_t
{
    IOS;
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}