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
        int a[n];
        int zeros = 0;
        map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            mp[a[i]]++;
            if (a[i] == 0)
                zeros++;
        }
        sort(a, a + n);
        int f = 0;
        for (int i = 0; i <= n; i++)
        {
            int temp = 0;
            int temp1 = 0;
            for (int j = 0; j < n; j++)
            {
                if (a[j] > i)
                    temp++;
                else
                    temp1++;
            }
            if (temp == i)
            {
                cout << i << endl;
                f = 1;
                break;
            }
        }
        if (f == 0)
            cout << -1 << endl;
    }
    return 0;
}

// 3 3 5 5 6 6