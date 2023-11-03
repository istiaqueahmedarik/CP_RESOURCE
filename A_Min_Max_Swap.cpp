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
        int arr[n], arr1[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        for (int i = 0; i < n; i++)
            cin >> arr1[i];
        for (int i = 0; i < n; i++)
        {
            if (arr[i] > arr1[i])
                swap(arr[i], arr1[i]);
        }
        int mx1 = *max_element(arr, arr + n);
        int mx2 = *max_element(arr1, arr1 + n);
        cout << mx1 * mx2 << endl;
    }
    return 0;
}