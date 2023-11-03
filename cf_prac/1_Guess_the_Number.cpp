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
    int low = 1, high = 1e6, ans = 0;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        cout << mid << endl;
        cout.flush();
        string s;
        cin >> s;
        if (s == ">=")
        {
            ans = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    cout << "! " << ans << endl;
    cout.flush();
    return 0;
}