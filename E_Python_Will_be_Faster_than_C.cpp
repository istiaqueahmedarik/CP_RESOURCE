#include <bits/stdc++.h>
#define lili long long int;
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    int a[n + 1];
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (a[i] < k)
        {
            cout << "Python 3." << i << " will be faster than C++\n";
            return;
        }
    }
    int diff = a[n - 1] - a[n];
    if (diff <= 0)
    {
        cout << "Python will never be faster than C++\n";
        return;
    }
    int ver = (a[n] - k) / diff;
    cout << "Python 3." << n + ver + 1 << " will be faster than C++\n";
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin >> t;
    for (int tc = 1; tc <= t; tc++)
    {
        // cout << "Case " << tc << ": ";
        solve();
    }
}
