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
        string s;
        cin >> s;
        int temp = 0;
        map<char, bool> prev;
        for (auto &i : s)
        {
            if (prev[i])
            {
                temp += 2;
                prev.clear();
            }
            else
                prev[i] = true;
        }
        cout << s.size() - temp << endl;
    }
    return 0;
}