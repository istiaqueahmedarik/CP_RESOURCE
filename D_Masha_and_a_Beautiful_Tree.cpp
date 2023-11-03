#include <bits/stdc++.h>
#define int long long
#define float double
#define endl '\n'
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);

using namespace std;
void process(int arr[], int leftInd, int rightInd, int &c)
{
    int mid = (leftInd + rightInd) / 2;
    int mx = LLONG_MIN, mn = LLONG_MAX;
    for (int i = leftInd; i <= mid; i++)
        mx = max(mx, arr[i]);
    for (int i = mid + 1; i <= rightInd; i++)
        mn = min(mn, arr[i]);
    if (mx > mn)
    {
        // cout << leftInd << " " << rightInd << " " << mid << endl;
        int tmp = mid + 1;
        for (int i = leftInd; i <= mid; i++)
        {
            // cout << arr[i] << " " << arr[tmp] << endl;
            swap(arr[i], arr[tmp++]);
        }
        c++;
    }
    if (leftInd == rightInd)
        return;
    process(arr, leftInd, mid, c);
    process(arr, mid + 1, rightInd, c);
}
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
        int c = 0;
        if (n > 1)
        {
            process(arr, 0, n - 1, c);
        }
        // for (int i = 0; i < n; i++)
        //     cout << arr[i] << " ";
        // cout << endl;
        if (is_sorted(arr, arr + n))
        {
            cout << c << endl;
        }
        else
        {
            cout << -1 << endl;
        }
    }
    return 0;
}
/*
    1 2 3 4
    0 1 2 3
    mid = 1;

*/