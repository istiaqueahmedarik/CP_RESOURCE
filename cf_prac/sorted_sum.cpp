#include <bits/stdc++.h>
#define int long long
#define float double
#define endl '\n'
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);

using namespace std;
#define M 1000000007
int sum(vector<int> &arr)
{
    int ans = 0;
    for (int i = 1; i <= arr.size(); i++)
    {
        ans += (arr[i - 1] * i) % M;
    }
    return ans;
}
int32_t main()
{
    IOS;
    int n;
    cin >> n;
    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        vector<int> sub;
        for (int j = 1; j <= i; j++)
        {
            sub.push_back(arr[j]);
        }
        sort(sub.begin(), sub.end());
        ans += sum(sub);
    }
    cout << ans << endl;
    return 0;
}