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
        multiset<int> s;
        while (1)
        {
            int x;
            cin >> x;
            if (x == 0)
                break;
            if (x == -1)
            {
                for (auto i : s)
                    cout << i << " ";
                cout << endl;
                int ind = s.size() / 2;
                if (s.size() % 2 == 0)
                    ind--;
                auto it = s.begin();
                advance(it, ind);
                cout << *it << endl;
                s.erase(it);
            }
            else
            {
                s.insert(x);
            }
        }
    }
    return 0;
}