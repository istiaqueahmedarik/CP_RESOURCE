#include <bits/stdc++.h>
#define int long long
#define float double
#define endl '\n'
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);

using namespace std;

// print bin for 8 bit
void print_bin(int x)
{
    for (int i = 7; i >= 0; i--)
    {
        if (x & (1 << i))
        {
            cout << 1;
        }
        else
        {
            cout << 0;
        }
    }
}

bool check(vector<int> arr, int n, int x)
{
    map<int, int> mp;
    // cout << "Extra:" << endl;
    // print_bin(x);
    // cout << endl;
    // for (auto i : arr)
    // {
    //     print_bin(i);
    //     cout << endl;
    // }
    for (int i = 0; i < n; i++)
    {
        arr[i] |= x;
        mp[arr[i]]++;
    }
    // cout << "x: " << x << endl;
    // for (int i = 0; i < n; i++)
    // {
    //     cout << arr[i] << " ";
    // }
    // cout << endl;

    return mp.size() >= 2;
}
int32_t main()
{
    IOS;
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        int low = 0, high = x;
        int ans = 0;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (check(a, n, mid))
            {
                ans = mid;
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
