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
    int sm = 0;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr + n, greater<int>());
    for (int i = 0; i < k; i++)
    {
        if (arr[i] < 0)
            continue;
        sm += arr[i];
    }
    cout << sm;
    return 0;
}