#include <bits/stdc++.h>
#define int long long
#define float double
#define endl '\n'
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);

using namespace std;
int p2(int n)
{
    int c = 0;
    while (n != 0 && n % 2 == 0)
    {
        n /= 2;
        c++;
    }
    return c;
}
bool cmp(pair<int, int> p, pair<int, int> q)
{
    return p2(p.first) < p2(q.first);
}
int32_t main()
{
    IOS;
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<pair<int, int>> arr;
        for (int i = 1; i <= n; i++)
        {
            int x;
            cin >> x;
            arr.push_back({i, x});
        }
        int c = 0;
        for (auto i : arr)
        {
            c += p2(i.second);
        }
        if (c >= n)
        {
            cout << 0 << endl;
            continue;
        }
        sort(arr.rbegin(), arr.rend(), cmp);
        int cnt = 0;
        // cout << c << endl;
        for (auto i : arr)
        {
            int temp = p2(i.first);
            // cout << i.first << " " << temp << endl;
            if (temp > 0)
            {
                cnt++;
            }
            c += temp;
            // cout << c << endl;
            if (c >= n)
                break;
        }
        if (c >= n)
            cout << cnt << endl;
        else
            cout << -1 << endl;
    }
    return 0;
}