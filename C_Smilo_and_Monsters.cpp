#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "debug.h"
#endif // !ONLI
using namespace std;
#define int long long
#define pi acos(-1)
#define endl '\n'
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
#define FileIO                        \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout)
const int MOD = 1e9 + 7, dx[] = {1, 0, -1, 0, 1, -1, -1, 1}, dy[] = {0, 1, 0, -1, 1, 1, -1, -1};
auto main() -> int32_t
{
    IOS;
    int t = 1, cs = 1;
    cin >> t;
    while (t--)
    {
        []() -> void
        {
            int a = 0, b = 1;
            function<void()> f = [&]() -> void
            {
                a++;
                b++;
            };
            f();
            cout << a << " " << b << endl;
        }

        return 0;
    }