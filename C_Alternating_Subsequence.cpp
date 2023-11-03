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
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        priority_queue<int> pq;
        int i = 0;
        int ans = 0;
        while (i < n)
        {
            if (arr[i] > 0)
                while (i < n && arr[i] > 0)
                    pq.push(arr[i++]);
            else
                while (i < n && arr[i] < 0)
                    pq.push(arr[i++]);
            ans += pq.top();
            while (!pq.empty())
                pq.pop();
        }
        cout << ans << endl;
    }
    return 0;
}