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
    for (int q = 1; q <= n; q++)
    {
        for (int i = n; i >= q + 1; i--)
        {
            cout << " ";
        }
        for (int i = 0; i < q - 1; i++)
        {
            if (q & 1)
            {
                cout << ">";
            }
            else
            {
                cout << "<";
            }
        }
        for (int i = 0; i < q; i++)
        {
            if (q & 1)
            {
                cout << ">";
            }
            else
            {
                cout << "<";
            }
        }
        cout << endl;
    }
    for (int q = n - 1; q >= 1; q--)
    {
        for (int i = n; i >= q + 1; i--)
        {
            cout << " ";
        }
        for (int i = 0; i < q - 1; i++)
        {
            if (q & 1)
            {
                cout << ">";
            }
            else
            {
                cout << "<";
            }
        }
        for (int i = 0; i < q; i++)
        {
            if (q & 1)
            {
                cout << ">";
            }
            else
            {
                cout << "<";
            }
        }
        cout << endl;
    }
    return 0;
}