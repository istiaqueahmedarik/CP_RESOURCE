#include <bits/stdc++.h>
#define int long long
#define float double
#define endl '\n'
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);

using namespace std;
void PRINT(stack<string> s)
{
    while (!s.empty())
    {
        cout << s.top() << endl;
        s.pop();
    }
}
int32_t main()
{
    IOS;
    int t;
    cin >> t;
    int cs = 1;
    while (t--)
    {
        cout << "Case " << cs++ << ":\n";
        stack<string> back;
        stack<string> forward;
        back.push("http://www.lightoj.com/");
        while (1)
        {

            string s;
            getline(cin, s);
            // cout << s << endl;
            char a = s[0];
            if (a == 'V')
            {
                string sub = s.substr(6, s.size() - 2);
                cout << sub << endl;
                back.push(sub);
                while (!forward.empty())
                {
                    forward.pop();
                }
            }
            else if (a == 'B')
            {
                forward.push(back.top());
                back.pop();
                if (back.empty())
                {
                    cout << "Ignored" << endl;
                    back.push(forward.top());
                    forward.pop();
                    continue;
                }
                cout << back.top() << endl;
            }
            else if (a == 'F')
            {
                if (forward.empty())
                {
                    cout << "Ignored" << endl;
                    continue;
                }

                cout << forward.top() << endl;
                back.push(forward.top());
                forward.pop();
            }

            else if (a == 'Q')
            {
                break;
            }
        }
    }
    return 0;
}