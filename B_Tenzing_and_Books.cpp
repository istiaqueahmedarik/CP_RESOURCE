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
        int n, x;
        cin >> n >> x;
        vector<int> arr1(n), arr2(n), arr3(n);
        for (int i = 0; i < n; i++)
            cin >> arr1[i];
        for (int i = 0; i < n; i++)
            cin >> arr2[i];
        for (int i = 0; i < n; i++)
            cin >> arr3[i];
        if (!x)
        {
            cout << "Yes" << endl;
        }
        else
        {
            int temp = 0;
            for (int i = 0; i < n; i++)
            {
                if ((arr1[i] | x) <= x)
                {
                    temp |= arr1[i];
                }
                else
                    break;
            }
            for (int i = 0; i < n; i++)
            {
                if ((arr2[i] | x) <= x)
                {
                    temp |= arr2[i];
                }
                else
                    break;
            }
            for (int i = 0; i < n; i++)
            {
                if ((arr3[i] | x) <= x)
                {
                    temp |= arr3[i];
                }
                else
                    break;
            }
            if (temp == x)
            {
                cout << "Yes" << endl;
            }
            else
            {
                cout << "No" << endl;
            }
        }
    }
    return 0;
}