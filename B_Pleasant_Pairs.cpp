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
        vector<int> arr(n + 1);
        for (int i = 1; i <= n; i++)
            cin >> arr[i];
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = arr[i] - i; j <= n; j += arr[i])
            {
                if (j < 0 || i >= j)
                    continue;
                if (arr[i] * arr[j] == i + j)
                    ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
/*
    1 2 3 4 5
    3 1 5 9 2
*/