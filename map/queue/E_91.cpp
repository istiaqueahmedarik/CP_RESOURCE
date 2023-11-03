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
    deque<int> dq;
    int cnt = 0;
    while (t--)
    {
        string s;
        cin >> s;
        if (s == "back")
        {
            if (dq.empty())
            {
                cout << "No job for Ada?" << endl;
            }
            else
            {
                if (cnt % 2 == 0)
                {
                    cout << dq.back() << endl;
                    dq.pop_back();
                }
                else
                {
                    cout << dq.front() << endl;
                    dq.pop_front();
                }
            }
        }
        else if (s == "front")
        {
            if (dq.empty())
            {
                cout << "No job for Ada?" << endl;
            }
            else
            {
                if (cnt % 2 == 0)
                {
                    cout << dq.front() << endl;
                    dq.pop_front();
                }
                else
                {
                    cout << dq.back() << endl;
                    dq.pop_back();
                }
            }
        }
        else if (s == "push_back")
        {
            int x;
            cin >> x;
            if (cnt % 2 == 0)
                dq.push_back(x);
            else
                dq.push_front(x);
        }
        else if (s == "reverse")
        {
            cnt++;
        }
        else if (s == "toFront")
        {
            int x;
            cin >> x;
            if (cnt % 2 == 0)
                dq.push_front(x);
            else
                dq.push_back(x);
        }
    }
    return 0;
}