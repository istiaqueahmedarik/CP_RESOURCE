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
        set<string> st;
        map<string, bool> mp;
        string temp1;
        int c = 0;
        for (int i = 0; i < n - 1; i++)
        {
            string temp = s.substr(i, 2);
            if (mp[temp] || mp[temp + temp1])
            {
            }
            else
            {
                c++;
            }
            temp1 += temp;
            mp[temp] = true;
            mp[temp1] = true;
            st.insert(temp);
        }
        cout << c << endl;
    }
    return 0;
}