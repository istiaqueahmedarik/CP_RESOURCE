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
        vector<int> arr1(n);
        int flag = 0, left = 0, right = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> arr1[i];
            if (arr[i] != arr1[i] && flag == 0)
            {
                left = i;
                flag = 1;
            }
        }
        int flag1 = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            if (arr[i] != arr1[i] && flag1 == 0)
            {
                right = i;
                flag1 = 1;
            }
            if (flag1 == 1)
                break;
        }
        vector<int> sub;
        for (int i = left; i <= right; i++)
        {
            sub.push_back(arr[i]);
        }
        int mx = *max_element(sub.begin(), sub.end());
        int mn = *min_element(sub.begin(), sub.end());
        while (1)
        {
            if (left <= 0)
                break;
            if (arr[left - 1] > mn)
                break;
            mn = min(mn, arr[left - 1]);
            left--;
        }
        while (1)
        {
            if (right >= n - 1)
                break;
            if (arr[right + 1] < mx)
                break;
            mx = max(mx, arr[right + 1]);
            right++;
        }
        cout << left + 1 << " " << right + 1 << endl;
    }
    return 0;
}