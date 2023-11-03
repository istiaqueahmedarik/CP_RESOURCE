#include <bits/stdc++.h>
using namespace std;
int dp[1001][1001];
int ans(int n, int cap, int wt[], int val[])
{
    dp[0][0] = 0;
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < cap; j++)
        {
            if (wt[i - 1] <= j)
            {
                dp[i][j] = max(val[i - 1] + dp[i - 1][j - wt[i - 1]], dp[i - 1][j]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n - 1][cap - 1];
}

int main()
{
    int n, cap;
    cin >> n >> cap;
    int wt[n], val[n];
    for (int i = 0; i < n; i++)
        cin >> wt[i];
    for (int i = 0; i < n; i++)
        cin >> val[i];
    cout << ans(n, cap, wt, val) << endl;
}