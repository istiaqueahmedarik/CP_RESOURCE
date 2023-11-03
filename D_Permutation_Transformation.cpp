#include <bits/stdc++.h>
#define int long long
#define float double
#define endl '\n'
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);

using namespace std;
vector<int> arr, ans;
int n;
void solve(int left, int right, int height)
{
    // cout << left << " " << right << " " << height << endl;
    int mx = LLONG_MIN, mxInd = 0;
    for (int i = left; i <= right; i++)
    {
        if (arr[i] > mx)
        {
            mx = arr[i];
            mxInd = i;
        }
    }
    ans[mxInd] = height;
    if (left <= mxInd - 1)
        solve(left, mxInd - 1, height + 1);
    if (right >= mxInd + 1)
        solve(mxInd + 1, right, height + 1);
}
int32_t main()
{
    IOS;
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        arr.resize(n, 0);
        ans.resize(n, 0);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        solve(0, n - 1, 0);
        for (auto i : ans)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}