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
        int n, m;
        cin >> n >> m;

        int l = 0;
        int r = 0;
        set<int> un;
        for (int i = 0; i < n; i++)
        {
            int temp;
            cin >> temp;
            if (temp == -2)
                l++;
            else if (temp == -1)
                r++;
            else
            {
                un.insert(temp);
            }
        }
        vector<int> arr;
        arr.push_back(-1);
        for (auto i : un)
            arr.push_back(i);
        arr.push_back(-2);
        int ans = 0;
        int p = arr.size();
        ans = max(ans, min(l + p - 2, m));
        for (int i = 1; i < p - 1; i++)
        {
            int temp1 = r + i - 1;
            int temp2 = l + p - i - 2;
            ans = max(ans, min(arr[i] - 1, temp1) + min(temp2, m - arr[i]) + 1);
        }
        ans = max(ans, min(r + p - 2, m));
        cout << ans << endl;
    }
    return 0;
}