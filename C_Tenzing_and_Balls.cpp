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
        vector<int> arr(n);
        vector<int> firstOcc(n + 1, -1), lastOcc(n + 1, -1);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            if (firstOcc[arr[i]] == -1)
                firstOcc[arr[i]] = i;
            else
                lastOcc[arr[i]] = i;
        }
        int ans = 0, ans1 = 0;
        for (int i = 0; i < n; i++)
        {
            if (lastOcc[arr[i]] != -1 && lastOcc[arr[i]] != i)
            {
                ans += lastOcc[arr[i]] - i + 1;
                i = lastOcc[arr[i]];
            }
        }
        for (int i = n - 1; i >= 0; i--)
        {
            if (lastOcc[arr[i]] != -1 && firstOcc[arr[i]] != i)
            {
                ans1 += i - firstOcc[arr[i]] + 1;
                i = firstOcc[arr[i]];
            }
        }
        cout << max(ans, ans1) << endl;
    }
    return 0;
}