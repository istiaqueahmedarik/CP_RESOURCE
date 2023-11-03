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
    int n, k;
    cin >> n >> k;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector<int> cng(n);
    cng[0] = 1;
    int c = 1;
    for (int i = 1; i <= n; i++)
    {
        c = arr[i] <= arr[i - 1] ? c + 1 : 1;
        cng[i] = c;
    }
    int arr1[n + 1];
    arr1[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        if (cng[i - 1] > 2)
        {
            arr1[i] = 1 + arr1[i - 1];
        }
        else
        {
            arr1[i] = arr1[i - 1];
        }
    }

    while (k--)
    {
        int l, r;
        cin >> l >> r;
        int c = arr1[r] - arr1[l - 1];
        cout << r - l + 1 - c << endl;
    }
    return 0;
}
