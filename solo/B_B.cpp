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
    int sm = n * (n + 1) / 2;
    if (sm & 1)
    {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES ";
    vector<int> v, v1;
    int sm1 = sm / 2;
    for (int i = n; i >= 1; i--)
    {
        if (i <= sm1)
        {
            v.push_back(i);
            sm1 -= i;
        }
        else
            v1.push_back(i);
    }
    cout << v.size() << " ";
    for (auto i : v)
        cout << i << " ";
    cout << v1.size() << " ";
    for (auto i : v1)
        cout << i << " ";
    return 0;
}