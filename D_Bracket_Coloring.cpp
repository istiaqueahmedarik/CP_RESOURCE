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
        string s;
        cin >> s;
        int c = 0;
        for (int i = 0; i < n; i++)
        {
            c += (s[i] == '(') ? 1 : -1;
        }
        if (c != 0)
        {
            cout << -1 << endl;
            continue;
        }
        int temp = 0, temp1 = 0;
        for (int i = 0; i < n; i++)
        {
            temp1 += (s[i] == '(') ? 1 : -1;
            if (temp1 < 0)
            {
                temp++;
                break;
            }
        }
        int temp2 = 0;
        for (int i = 0; i < n; i++)
        {
            temp2 += (s[i] == ')') ? 1 : -1;
            if (temp2 < 0)
            {
                temp++;
                break;
            }
        }
        if (temp >= 2)
        {
            vector<int> ans(n);
            int i = 0, j = n - 1;
            while (i < j)
            {

                if (s[i] == '(' && s[j] == '(')
                {
                    ans[i++] = 1;
                    ans[j--] = 2;
                }
                else if (s[i] == ')' && s[j] == ')')
                {
                    ans[i++] = 2;
                    ans[j--] = 1;
                }
                else if (s[i] == ')' && s[j] == '(')
                {
                    ans[j--] = 2;
                    ans[i++] = 2;
                }
                else
                {
                    ans[i++] = 1;
                    ans[j--] = 1;
                }
            }
            cout << 2 << endl;
            for (auto i : ans)
            {
                cout << i << " ";
            }
            cout << endl;
        }
        else
        {
            cout << 1 << endl;
            for (int i = 0; i < n; i++)
            {
                cout << 1 << " ";
            }
            cout << endl;
        }
    }
    return 0;
}