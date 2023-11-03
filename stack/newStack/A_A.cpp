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
    while (cin >> n)
    {
        stack<int> s;
        queue<int> q;
        priority_queue<int> pq;
        bool isStack = true, isQueue = true, isPQ = true;
        while (n--)
        {
            int op, x;
            cin >> op >> x;
            if (op == 1)
            {
                s.push(x);
                q.push(x);
                pq.push(x);
            }
            else
            {
                if (s.empty() || s.top() != x)
                    isStack = false;
                else
                    s.pop();
                if (q.empty() || q.front() != x)
                    isQueue = false;
                else
                    q.pop();
                if (pq.empty() || pq.top() != x)
                    isPQ = false;
                else
                    pq.pop();
            }
        }
        if (isStack + isQueue + isPQ > 1)
            cout << "not sure" << endl;
        else if (isStack)
            cout << "stack" << endl;
        else if (isQueue)
            cout << "queue" << endl;
        else if (isPQ)
            cout << "priority queue" << endl;
        else
            cout << "impossible" << endl;
    }
    return 0;
}