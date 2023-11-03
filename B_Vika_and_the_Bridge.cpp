#include <bits/stdc++.h>
#define int long long
#define float double
#define endl '\n'
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);

using namespace std;
void Print(priority_queue<int> pq)
{
    while (!pq.empty())
    {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;
}
int32_t main()
{
    IOS;
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> colors(n);
        vector<int> initial(k + 1, -1);
        for (int i = 0; i < n; i++)
        {
            cin >> colors[i];
        }
        map<int, priority_queue<int>> maxDist;
        for (int i = 0; i < n; i++)
        {
            int dist = i - initial[colors[i]] - 1;
            initial[colors[i]] = i;
            maxDist[colors[i]].push(dist);
        }
        for (int i = 1; i <= k; i++)
        {
            int dist = n - initial[i] - 1;
            // cout << i << " " << dist << endl;
            maxDist[i].push(dist);
        }
        int ans = LLONG_MAX;
        for (auto i : maxDist)
        {
            // cout << i.first << "-->" << endl;
            // Print(i.second);
            int mx = i.second.top();
            i.second.pop();
            if (!i.second.empty())
            {
                if (mx == i.second.top())
                    ans = min(ans, mx);
                else
                    ans = min(ans, max(mx / 2, i.second.top()));
            }
            else
                ans = min(ans, mx / 2);
        }
        cout << ans << endl;
    }
    return 0;
}