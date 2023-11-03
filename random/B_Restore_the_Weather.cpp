#include <bits/stdc++.h>
#define int long long
#define float double
#define endl '\n'
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);

using namespace std;
bool checker(vector<int> &v, int arr[], int k)
{
    bool flag = true;
    for (int i = 0; i < v.size(); i++)
    {
        if (abs(v[i] - arr[i]) > k)
        {
            cout << v[i] << " " << arr[i] << endl;
            return false;
        }
    }
    return true;
}
int32_t main()
{
    IOS;
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int a[n];
        vector<pair<int, int>> vp;
        int b[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            vp.push_back({a[i], i});
        }
        sort(vp.begin(), vp.end());
        for (int i = 0; i < n; i++)
            cin >> b[i];
        sort(b, b + n);
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            v[vp[i].second] = b[i];
        }
        for (auto i : v)
        {
            cout << i << " ";
        }
        cout << endl;
        // cout << checker(v, a, k) << endl;
    }
    return 0;
}

/*
 */