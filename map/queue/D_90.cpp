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
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            pq.push(x);
        }
        int ans = 0;
        while (pq.size() != 1)
        {
            int x = pq.top();
            pq.pop();
            int y = pq.top();
            pq.pop();
            ans += x + y;
            pq.push(x + y);
        }
        cout << ans << endl;
    }
    return 0;
}