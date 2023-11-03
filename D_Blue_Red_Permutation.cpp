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
        {
            cin >> arr[i];
        }
        vector<int> r, b;
        string s;
        cin >> s;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'R')
            {
                r.push_back(arr[i]);
            }
            else
            {
                b.push_back(arr[i]);
            }
        }
        sort(r.rbegin(), r.rend());
        sort(b.begin(), b.end());
        bool flag = true;
        for (int i = 0; i < b.size(); i++)
        {
            if (b[i] < i + 1)
            {
                flag = false;
                break;
            }
        }
        for (int i = 0; i < r.size(); i++)
        {
            if (r[i] > n - i)
            {
                flag = false;
                break;
            }
        }
        if (flag)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}