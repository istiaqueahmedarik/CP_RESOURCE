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
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        sort(a.begin(), a.end());
        int low = 0, high = 1e9, ans = 0;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            bool flag = false;
            int c = 1;
            int temp = a[0];
            for (int i = 1; i < n; i++)
            {
                if (((a[i] - temp + 1) / 2) > mid)
                {
                    c++;
                    temp = a[i];
                }
            }
            if (c <= 3)
                flag = true;
            if (flag)
            {
                ans = mid;
                high = mid - 1;
            }
            else
                low = mid + 1;
        }
        cout << ans << endl;
    }
    return 0;
}