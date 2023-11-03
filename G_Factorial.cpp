#include <bits/stdc++.h>
#define int long long
#define float double
#define endl '\n'
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);

using namespace std;
int fact[25];
void init()
{
    fact[0] = 1;
    fact[1] = 1;
    for (int i = 2; i < 25; i++)
    {
        fact[i] = fact[i - 1] * i;
    }
}
int32_t main()
{
    IOS;
    int t;
    cin >> t;
    init();
    while (t--)
    {
        int x;
        cin >> x;
        cout << fact[x] << endl;
    }
    return 0;
}