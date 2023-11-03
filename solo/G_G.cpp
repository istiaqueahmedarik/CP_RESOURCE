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
    int n;
    cin >> n;
    map<int, int> mp;
    vector<int> v(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
        mp[v[i]]++;
    }
    sort(v.begin(), v.end());
    int ans = 1;
    map<int, int> N;
    for (int i = 1; i <= 3; i++)
    {
        ans *= mp[v[i]];
        mp[v[i]]--;
        N[v[i]]++;
    }
    for (int i = 1; i <= 3; i++)
    {
        ans /= N[v[i]];
        N[v[i]]--;
    }
    cout << ans;

    return 0;
}