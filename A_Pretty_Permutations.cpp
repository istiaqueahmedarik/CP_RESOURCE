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
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            arr[i] = i + 1;
        if (n & 1)
        {
            for (int i = 0; i < n - 3; i += 2)
            {
                swap(arr[i], arr[i + 1]);
            }
            swap(arr[n - 1], arr[n - 3]);
            swap(arr[n - 3], arr[n - 2]);
        }
        else
        {
            for (int i = 0; i < n; i += 2)
            {
                swap(arr[i], arr[i + 1]);
            }
        }
        for (auto i : arr)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}