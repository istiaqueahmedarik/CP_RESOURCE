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
    t *= 2;
    stack<int> st;
    int i = 1;
    int ans = 0;
    while (t--)
    {
        string s;
        cin >> s;
        if (s == "add")
        {
            int x;
            cin >> x;
            st.push(x);
        }
        else if (s == "remove")
        {
            if (!st.empty())
            {
                if (st.top() == i)
                {
                    st.pop();
                }
                else
                {
                    ans++;
                    while (!st.empty())
                    {
                        st.pop();
                    }
                }
            }
            i++;
        }
    }
    cout << ans << endl;
    return 0;
}