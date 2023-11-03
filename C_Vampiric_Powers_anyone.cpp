#include <bits/stdc++.h>
#define int long long
#define float double
#define endl '\n'
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);

using namespace std;
int max_xor_subarray(vector<int> &arr)
{
    int max_xor = 0;
    int prefix_xor = 0;
    unordered_set<int> prefix_xor_set;
    prefix_xor_set.insert(0);
    for (int num : arr)
    {
        prefix_xor ^= num;
        prefix_xor_set.insert(prefix_xor);

        for (int val : prefix_xor_set)
        {
            max_xor = max(max_xor, prefix_xor ^ val);
        }
    }

    return max_xor;
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
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        cout << max_xor_subarray(arr) << endl;
    }
    return 0;
}