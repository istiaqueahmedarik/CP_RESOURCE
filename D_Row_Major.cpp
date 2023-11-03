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
        set<int> squares;
        for (int i = 1; i * i <= n; i++)
        {
            if (n % i == 0)
            {
                squares.insert(i);
                squares.insert(n / i);
            }
        }
        int x = 1;
        for (auto i : squares)
        {
            if (i == x)
                x++;
            else
                break;
        }
        for (int i = 0; i < n; i++)
        {
            char p = (i % x) + 'a';
            cout << p;
        }
        cout << endl;
    }
    return 0;
}