#include <bits/stdc++.h>
#define int long long
#define float double
#define endl '\n'
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);

using namespace std;
int n;
vector<int> coins;
vector<vector<int>> dp(105, vector<int>(100005, -1));
bool possible(int ind, int sum)
{
    if (sum == 0)
        return true;
    if (ind >= n)
        return false;
    if (sum < 0)
        return false;
    if (dp[ind][sum] != -1)
        return dp[ind][sum];
    return dp[ind][sum] = possible(ind + 1, sum) | possible(ind + 1, sum - coins[ind]);
}
int32_t main()
{
    IOS;
    cin >> n;
    set<int> ans;
    int sm = 0;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        sm += x;
        coins.emplace_back(x);
    }
    ans.insert(sm);
    sort(coins.begin(), coins.end());
    for (int i = sm - 1; i >= 1; i--)
    {
        if (possible(0, i))
            ans.insert(i);
    }
    cout << ans.size() << endl;
    for (auto i : ans)
        cout << i << " ";
    cout << endl;
    return 0;
}