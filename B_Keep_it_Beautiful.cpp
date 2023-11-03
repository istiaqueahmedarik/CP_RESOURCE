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
        {
            cin >> arr[i];
        }
        int x = arr[0];
        int flagInd = -1;
        int ans[n];
        ans[0] = 1;
        int temp = arr[0];
        for (int i = 1; i < n; i++)
        {
            if (arr[i] >= temp)
            {
                temp = arr[i];
                ans[i] = 1;
            }
            else if (arr[i] <= x)
            {
                ans[i] = 1;
                flagInd = i;
                temp = arr[i];
                break;
            }
            else
                ans[i] = 0;
        }
        if (flagInd != -1)
        {
            for (int i = flagInd + 1; i < n; i++)
            {
                if (arr[i] <= x && arr[i] >= temp)
                {
                    temp = arr[i];
                    ans[i] = 1;
                }
                else
                    ans[i] = 0;
            }
        }
        for (int i = 0; i < n; i++)
            cout << ans[i];
        cout << endl;
    }
    return 0;
}