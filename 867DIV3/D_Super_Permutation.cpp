#include <bits/stdc++.h>
#define int long long
#define float double
#define endl '\n'
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);

using namespace std;

bool validator(vector<int> &v)
{
    vector<int> temp;
    for (int i = 0; i < v.size(); i++)
    {
        int sum = 0;
        for (int j = 0; j <= i; j++)
        {
            sum += v[j];
        }
        temp.push_back(sum % v.size() + 1);
    }
    sort(temp.begin(), temp.end());
    for (int i = 1; i <= v.size(); i++)
    {
        if (temp[i - 1] != i)
        {
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
        int n;
        cin >> n;
        if (n == 1)
        {
            cout << 1 << endl;
            continue;
        }
        if (n & 1)
        {
            cout << -1 << endl;
            continue;
        }

        vector<int> ans(n);
        int val = n;
        for (int i = 0; i < n; i += 2)
        {
            ans[i] = val;
            val -= 2;
        }
        val = n - 1;
        for (int i = n - 1; i > 0; i -= 2)
        {
            ans[i] = val;
            val -= 2;
        }
        for (int i = 0; i < n; i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
