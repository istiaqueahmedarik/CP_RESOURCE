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
        int n, l, r;
        cin >> n >> l >> r;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        sort(arr.begin(), arr.end());
        int total = 0;
        int j = 0;
        for (auto i : arr)
        {
            auto lowInd = lower_bound(arr.begin() + j + 1, arr.end(), l - i);
            auto upInd = upper_bound(arr.begin() + j++ + 1, arr.end(), r - i);
            total += (upInd - lowInd);
            // cout << i << " " << lowInd << " " << upInd << " " << upInd - lowInd << endl;
        }
        cout << total << endl;
    }
    return 0;
}