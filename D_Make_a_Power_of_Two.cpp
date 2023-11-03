#include <bits/stdc++.h>
#define int long long
#define float double
#define endl '\n'
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);

using namespace std;
vector<string> all;
void init()
{
    int n = 1;
    all.push_back("1");
    for (int i = 0; i < 62; i++)
    {
        n <<= 1;
        all.push_back(to_string(n));
    }
}
int32_t main()
{
    IOS;
    init();
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        int ans = LLONG_MAX;
        cin >> n;
        string s = to_string(n);
        for (int i = 0; i < all.size(); i++)
        {
            int same = 0;
            int j = 0;
            for (int k = 0; k < s.size(); k++)
            {
                if (all[i][j] == s[k] && j < all[i].size())
                    same++, j++;
            }
            int temp = (s.size() - same) + (all[i].size() - same);
            ans = min(ans, temp);
        }
        cout << ans << endl;
    }
    return 0;
}