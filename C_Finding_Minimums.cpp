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
    int n, k;
    cin >> n >> k;
    vector<int> ans, arr(n);
    int mn = LLONG_MAX;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i - 1];
        if (i % k == 0)
        {
            ans.push_back(min(mn, arr[i - 1]));
            mn = LLONG_MAX;
        }
        else
        {
            mn = min(mn, arr[i - 1]);
        }
    }
    if (mn != LLONG_MAX)
        ans.push_back(mn);
    for (auto i : ans)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}