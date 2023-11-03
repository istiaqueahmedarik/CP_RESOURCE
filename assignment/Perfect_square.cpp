#include <bits/stdc++.h>
using namespace std;
int dp[100000];
int ans(int n)
{
    if (dp[n] != 0)
        return dp[n];
    int mn = INT_MAX;
    for (int i = 1; i * i <= n; i++)
    {
        if (i * i == n)
        {
            return 1;
        }
        mn = min(mn, ans(n - i * i));
    }
    return dp[n] = mn + 1;
}
int main()
{
    int n;
    cin >> n;
    cout << ans(n) << endl;
}