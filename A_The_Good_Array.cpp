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
        int n, k;
        cin >> n >> k;
        vector<int> a(n + 1);
        a[1] = a[n] = 1;
        int temp = 1;
        while (k * temp < n)
        {
            a[k * temp + 1] = 1;
            temp++;
        }
        int c = 0;
        for (auto i : a)
        {
            if (i)
                c++;
        }
        cout << c << endl;
    }
    return 0;
}