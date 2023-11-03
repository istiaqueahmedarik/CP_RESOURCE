#include <bits/stdc++.h>
#define int long long
#define float double
#define endl '\n'
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);

using namespace std;
int ncr(int n, int r)
{
    if (r == 0 || r == n)
        return 1;
    return ncr(n - 1, r - 1) + ncr(n - 1, r);
}

int32_t main()
{
    IOS;
    int t;
    cin >> t;
    while (t--)
    {
        int n, q;
        cin >> n >> q;
        vector<int> arr(n + 1);
        for (int i = 1; i <= n; i++)
            cin >> arr[i];
        sort(arr.begin(), arr.end());
        int highest = 1;
        vector<int> step;
        for (int i = 2; i < n; i++)
        {
            step.push_back(highest);
            highest += i;
        }
        reverse(step.begin(), step.end());
        vector<int> query(step.size());
        for (int i = 0; i < step.size(); i++)
        {
            if (i == 0)
                query[i] = step[i];
            else
                query[i] = step[i] + query[i - 1];
        }
        while (q--)
        {
            int n;
            cin >> n;
            int idx = lower_bound(query.begin(), query.end(), n) - query.begin();
            cout << arr[idx + 1] << endl;
        }
    }
    return 0;
}

/*
    45->36->28->21->15->10->6->3->1
*/