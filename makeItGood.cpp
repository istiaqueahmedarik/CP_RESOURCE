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
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        int pivot = n - 1;
        for (; pivot > 0 && v[pivot - 1] >= v[pivot]; pivot--)
            ;
        for (; pivot > 0 && v[pivot - 1] <= v[pivot]; pivot--)
            ;
        cout << pivot << endl;
    }
    return 0;
}