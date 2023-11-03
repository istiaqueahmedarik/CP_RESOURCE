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
        map<int, int> mp, mp1;
        int initial = arr[0];
        int temp = 1;
        for (int i = 1; i < n; i++)
        {
            if (arr[i] == initial)
                temp++;
            else
            {
                mp[initial] = max(mp[initial], temp);
                initial = arr[i];
                temp = 1;
            }
        }
        mp[initial] = max(mp[initial], temp);

        initial = arr1[0];
        temp = 1;
        for (int i = 1; i < n; i++)
        {
            if (arr1[i] == initial)
                temp++;
            else
            {
                mp1[initial] = max(mp1[initial], temp);
                initial = arr1[i];
                temp = 1;
            }
        }
        mp1[initial] = max(mp1[initial], temp);

        int mx = -1;
        for (auto i : mp)
        {
            mx = max(mx, i.second + mp1[i.first]);
        }
        for (auto i : mp1)
        {
            mx = max(mx, i.second + mp[i.first]);
        }

        cout << mx << endl;
    }
    return 0;
}