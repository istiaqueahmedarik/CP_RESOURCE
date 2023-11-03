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
        map<int, multiset<int>> mp;
        for (int i = 1; i <= n; i++)
        {
            int a, b;
            cin >> a >> b;
            mp[a].insert(b);
        }
        int c = 0;
        for (int i = 1; i <= n; i++)
        {
            int temp = 0;
            multiset<int>::reverse_iterator it;
            for (it = mp[i].rbegin(); it != mp[i].rend(); it++)
            {
                if (temp >= i)
                    break;
                c += *it;
                temp++;
            }
        }
        cout << c << endl;
    }
    return 0;
}