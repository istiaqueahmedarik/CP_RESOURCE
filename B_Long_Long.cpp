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
        int sm = 0;
        int arr[n];
        int neg = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            sm += abs(arr[i]);
        }
        int c = 0;
        int temp = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] < 0)
            {
                temp++;
            }
            else if (arr[i] == 0 && temp > 0)
                temp++;
            else if (temp > 0)
            {
                c++;
                temp = 0;
            }
        }
        if (temp > 0)
            c++;
        cout << sm << " " << c << endl;
    }
    return 0;
}