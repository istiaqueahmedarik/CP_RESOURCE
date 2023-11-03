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
        map<int, int> mp;
        pair<int, int> possible;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            mp[arr[i]] = i + 1;
        }
        int one = mp[1];
        int two = mp[2];
        int pivot = mp[*max_element(arr.begin(), arr.end())];
        bool flag = (one > pivot && two > pivot), flag1 = (one < pivot && two < pivot);
        if (flag || flag1)
        {
            if (flag)
            {
                cout << min(one, two) << " " << pivot << endl;
            }
            else
            {
                cout << max(one, two) << " " << pivot << endl;
            }
        }
        else
        {
            cout << 1 << " " << 1 << endl;
        }
    }
    return 0;
}