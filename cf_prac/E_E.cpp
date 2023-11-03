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
        vector<int> arr;
        vector<int> set_bits(32, 0);
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            arr.push_back(x);
            for (int j = 0; j < 32; j++)
            {
                if (x & (1 << j))
                {
                    set_bits[j]++;
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < 32; i++)
        {
            if (set_bits[i] >= 2)
            {
                ans += pow(2, i);
            }
        }
        cout << ans << endl;
    }
    return 0;
}