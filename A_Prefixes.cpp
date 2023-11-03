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
    string s;
    cin >> s;
    int i = 0, j = 1;
    int c = 0;
    string ans;
    while (j <= n - 1)
    {
        int a = 0, b = 0;
        if (s[i] == 'a')
            a++;
        else
            b++;
        if (s[j] == 'a')
            a++;
        else
            b++;
        if (a != b)
        {
            c++;
            ans += "ab";
        }
        else
        {

            ans += s[i];
            ans += s[j];
        }
        i += 2;
        j += 2;
    }
    cout << c << endl;
    cout << ans << endl;
}
auto main() -> int32_t
{
    IOS;
    int t = 1, cs = 1;
    while (t--)
    {
        solve();
    }

    return 0;
}