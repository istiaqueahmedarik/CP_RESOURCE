#include <bits/stdc++.h>
#define int long long
#define float double
#define endl '\n'
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);

using namespace std;
string l, r, s;
int m;
bool flag = false;
void Subsequence(string tmp, int ind)
{
    if (ind == m)
    {
        int temp = 0;
        for (auto i : s)
        {
            if (temp < m && i == tmp[temp])
                temp++;
        }
        if (temp != m)
            flag = true;
        return;
    }
    for (int i = l[ind] - '0'; i <= r[ind] - '0'; i++)
    {
        tmp.push_back(i + '0');
        Subsequence(tmp, ind + 1);
        tmp.pop_back();
    }
}
int32_t main()
{
    IOS;
    int t;
    cin >> t;
    while (t--)
    {
        flag = false;
        cin >> s;
        cin >> m;
        cin >> l >> r;
        string tmp;
        Subsequence(tmp, 0);
        if (flag)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}