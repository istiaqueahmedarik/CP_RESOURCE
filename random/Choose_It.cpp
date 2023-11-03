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
    int n, w;
    cin >> n >> w;
    vector<int> box(n);
    vector<int> weight(n);
    for (int i = 0; i < n; i++)
    {
        cin >> box[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> weight[i];
    }
    vector<int> dp(w + 1, 0);
    for (int i = weight[0]; i <= w; i++)
    {
        dp[i] = ((int)i / weight[0]) * box[0];
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= w; j++)
        {
            int temp = LLONG_MIN;
            if (weight[i] <= j)
            {
                temp = box[i] + dp[j - weight[i]];
            }
            dp[j] = max(dp[j], temp);
        }
    }
    cout << dp[w] << endl;
    return 0;
}
