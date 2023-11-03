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
        vector<int> v(n);
        map<int, int> m;
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            m[v[i]]++;
        }
        sort(v.begin(), v.end());
        int mx = *max_element(v.begin(), v.end());
        int flag = 0;
        int mxF = m[0];
        for (int i = 1; i <= mx; i++)
        {
            if (m[i] == 0 || m[i] > mxF)
            {
                flag = 1;
                cout << "NO\n";
                break;
            }
            else
                mxF = max(mxF, m[i]);
        }
        if (!flag)
            cout << "YES\n";
    }
    return 0;
}