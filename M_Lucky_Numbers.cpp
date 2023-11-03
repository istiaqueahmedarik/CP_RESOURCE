#include <bits/stdc++.h>
#define int long long
#define float double
#define endl '\n'
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);

using namespace std;
bool checker(int n)
{
    while (n != 0)
    {
        if (n % 10 != 4 && n % 10 != 7)
            return false;
        n /= 10;
    }
    return true;
}
int32_t main()
{
    IOS;
    int a, b;
    cin >> a >> b;
    vector<int> v;
    for (int i = a; i <= b; i++)
    {
        if (checker(i))
        {
            cout << i << " ";
            v.push_back(i);
        }
    }

    if (v.empty())
        cout << -1 << endl;
    cout << endl;
    return 0;
}