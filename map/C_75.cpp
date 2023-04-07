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
    int n;
    cin >> n;
    map<int, int> mp;
    int flag = 1;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;

        mp[x]++;
    }
    for (auto i : mp)
    {
        if (i.second % 2)
        {
            flag = 0;
            break;
        }
    }
    if (flag)
    {
        cout << "Agasa" << endl;
    }
    else
    {
        cout << "Conan" << endl;
    }
    return 0;
}