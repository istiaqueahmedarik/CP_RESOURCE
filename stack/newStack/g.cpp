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
    map<int, int> recent_min;
    int arr[n];
    stack<int> s;
    stack<int> index;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        arr[i] = x;
        if (s.empty())
        {
            s.push(x);
            index.push(i);
        }
        else
        {
            if (x > s.top())
            {
                s.push(x);
                index.push(i);
            }
            else
            {
                while (!s.empty() && x < s.top())
                {
                    recent_min[index.top()] = i;
                    index.pop();
                    s.pop();
                }
                s.push(x);
                index.push(i);
            }
        }
    }
    while (!s.empty())
    {
        recent_min[index.top()] = n;
        index.pop();
        s.pop();
    }
    map<int, int> recent_min1;

    for (int i = n - 1; i >= 0; i--)
    {
        int x = arr[i];
        if (s.empty())
        {
            s.push(x);
            index.push(i);
        }
        else
        {
            if (x > s.top())
            {
                s.push(x);
                index.push(i);
            }
            else
            {
                while (!s.empty() && x < s.top())
                {
                    recent_min1[index.top()] = i;
                    index.pop();
                    s.pop();
                }
                s.push(x);
                index.push(i);
            }
        }
    }
    while (!s.empty())
    {
        recent_min1[index.top()] = -1;
        index.pop();
        s.pop();
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += (recent_min[i] - i) * (i - recent_min1[i]) * arr[i];
    }
    cout << ans << endl;

    return 0;
}

/*

*/