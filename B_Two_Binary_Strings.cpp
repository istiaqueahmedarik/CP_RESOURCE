#include <bits/stdc++.h>
#define endl "\n"
#define int long long

using namespace std;
int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)

    {
        string a, b;
        cin >> a >> b;
        if (a == b)
            cout << "YES\n";
        else
        {
            int zero, one;
            int f1 = 0, f2 = 0;
            for (int i = 1; i < a.length() - 1; i++)
            {
                if (a[i] == '0' and b[i] == '0')
                {
                    zero = i;
                    f1 = 1;
                }
            }
            for (int i = 1; i < a.length() - 1; i++)
            {
                if (a[i] == '1' and b[i] == '1')
                {
                    one = i;
                    f2 = 1;
                    break;
                }
            }
            // cout<<one<<" "<<zero<<endl;
            if (f1 == 1 or f2 == 1)
            {
                if (zero == a.length() - 2)
                    cout << "YES\n";
                else if (one == 1)
                    cout << "YES\n";
                else if (one - zero == 1 and f1 == 1 and f2 == 1)
                    cout << "YES\n";
                else
                    cout << "NO\n";
            }
            else
                cout << "NO\n";
        }
    }
}