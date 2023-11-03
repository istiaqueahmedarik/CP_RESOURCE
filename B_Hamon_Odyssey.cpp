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
        int ans = 0;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        const int mxOne = 1073741823;
        int temp = mxOne, temp2 = mxOne;
        for (int i = 0; i < n; i++)
        {
            temp &= arr[i];
            temp2 &= arr[i];
            if (!temp)
            {
                ans++;
                temp = mxOne;
            }
        }
        if (temp2)
            ans++;
        cout << ans << endl;
    }
    return 0;
}