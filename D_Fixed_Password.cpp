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
    while (cin >> t)
    {
        if (t == 1999)
        {
            cout << "Correct" << endl;
            break;
        }
        else
            cout << "Wrong" << endl;
    }
    return 0;
}