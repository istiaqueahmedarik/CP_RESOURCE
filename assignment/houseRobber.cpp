#include <bits/stdc++.h>
using namespace std;
int dp[100000];
int ans(vector<int> &arr, int i, int n)
{
    if (i >= n)
        return 0;
    if (dp[i])
        return dp[i];
    return dp[i] = max(arr[i] + ans(arr, i + 2, n), ans(arr, i + 1, n));
}
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << max({ans(arr, 1, n), ans(arr, 0, n - 1), arr[0]}) << endl;
}