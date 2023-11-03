#include <bits/stdc++.h>
using namespace std;
int dp[10000][2];
int ans(vector<int> &arr, int i, bool types)
{
    if (i >= arr.size() || i == arr.size() - 1 && types == 1)
        return 0;
    if (dp[i][types] != -1)
        return dp[i][types];
    if (i == 0)
        return dp[i][types] = max(arr[i] + ans(arr, i + 2, 1), ans(arr, i + 1, types));
    return dp[i][types] = max(arr[i] + ans(arr, i + 2, types), ans(arr, i + 1, types));
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    memset(dp, -1, sizeof(dp));

    cout << ans(arr, 0, 0);
}