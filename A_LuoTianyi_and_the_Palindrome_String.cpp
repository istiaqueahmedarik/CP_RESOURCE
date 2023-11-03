#include <bits/stdc++.h>
#define int long long
#define float double
#define endl '\n'
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);

using namespace std;
bool palindrom(string s)
{
    for (int i = 0; i < s.size() / 2; i++)
    {
        if (s[i] != s[s.size() - i - 1])
        {
            return false;
        }
    }
    return true;
}
int32_t main()
{
    IOS;
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        string temp = s;
        int low = 0;
        int high = s.size() - 1;
        int length = s.size();
        int c = 0;
        bool flag = false;
        while (length != 0)
        {
            if (palindrom(s))
            {
                s.pop_back();
                c++;
                length--;
            }
            else
            {
                break;
            }
            if (length == 0)
            {
                cout << -1 << endl;
                flag = true;
                break;
            }
        }
        if (!flag)
        {
            cout << temp.length() - c << endl;
        }
    }
    return 0;
}