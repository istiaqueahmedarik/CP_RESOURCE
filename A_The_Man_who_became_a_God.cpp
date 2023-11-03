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
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        int ans = 0;
        vector<int> diff;
        for (int i = 0; i < n - 1; i++)
        {
            diff.push_back(abs(arr[i] - arr[i + 1]));
        }
        sort(diff.begin(), diff.end());
        for (int i = 0; i < n - k; i++)
        {
            ans += diff[i];
        }
        cout << ans << endl;
    }
    return 0;
}
/*
    1 9 8 2 3 3 1 8 7 7 9 2
    1 1 2 2 3 3 7 7 8 8 9 9
*/