#include <bits/stdc++.h>
#define int long long
#define float double
#define endl '\n'
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);

using namespace std;
int dp[1000005];
int ans(int n, vector<int> &v, map<int, int> &mp)
{
    dp[0] = 0;
    dp[1] = mp[1];
    for (int i = 2; i <= n; i++)
    {
        dp[i] = max(dp[i - 1], dp[i - 2] + i * mp[i]);
    }
    return dp[n];
}
int32_t main()
{
    IOS;
    int n;
    cin >> n;
    vector<int> v(n);
    map<int, int> mp;
    int mx = -1;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        mp[v[i]]++;
        mx = max(mx, v[i]);
    }
    cout << ans(mx, v, mp) << endl;
    return 0;
}