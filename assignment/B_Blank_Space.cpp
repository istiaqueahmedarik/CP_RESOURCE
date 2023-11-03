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
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        int ans = 0;
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == 0)
                count++;
            else
            {
                ans = max(ans, count);
                count = 0;
            }
        }
        ans = max(ans, count);

        cout << ans << endl;
    }
    return 0;
}