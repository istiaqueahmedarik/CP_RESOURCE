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
        int n, k;
        cin >> n >> k;
        multimap<int, int> mp;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            mp.insert({arr[i], x});
        }
        for (auto i : mp)
        {
            if (k >= i.first)
                k += i.second;
        }

        cout << k << endl;
    }
    return 0;
}