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
        vector<pair<int, string>> arr(n);
        int flag = 0;
        int min_for11 = INT_MAX;
        bool flag2 = 0;
        int min_for01 = INT_MAX;
        bool flag3 = 0;
        int min_for10 = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i].first;
            cin >> arr[i].second;
            if (arr[i].second == "11")
            {
                min_for11 = min(min_for11, arr[i].first);
                flag = 1;
            }
            if (arr[i].second == "01")
            {
                flag2 = 1;
                min_for01 = min(min_for01, arr[i].first);
            }
            if (arr[i].second == "10")
            {
                flag3 = 1;
                min_for10 = min(min_for10, arr[i].first);
            }
        }
        if (flag)
        {
            if (!flag2 || !flag3)
            {
                cout << min_for11 << endl;
            }
            else
            {
                cout << min(min_for11, min_for01 + min_for10) << endl;
            }
        }
        else if (!flag2 || !flag3)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << min_for01 + min_for10 << endl;
        }
    }
    return 0;
}