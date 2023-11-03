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
        int arr[n + 1];
        for (int i = 1; i <= n; i++)
            cin >> arr[i];
        int ans = 0;
        int i = n;
        int lasElement = arr[i];
        while (i > 0)
        {
            if (i == 1)
                break;
            int length = n - i + 1;
            if (i > 1 && lasElement == arr[i - 1])
                i--;
            else
                ans++, i -= length;
        }
        cout << ans << endl;
    }
    return 0;
}