#include <bits/stdc++.h>
#define int long long
#define float double
#define endl '\n'
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);

using namespace std;

void PRINT(stack<int> s)
{
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

int32_t main()
{
    IOS;
    int n;
    while (cin >> n && n)
    {
        int x;
        while (cin >> x && x)
        {
            vector<int> arr;
            arr.push_back(x);
            for (int i = 0; i < n - 1; i++)
            {
                int p;
                cin >> p;
                arr.push_back(p);
            }
            stack<int> s;
            int j = 0;
            for (int i = 1; i <= n; i++)
            {
                s.push(i);
                // cout << s.top() << " " << arr[j] << endl;
                while (!s.empty() && s.top() == arr[j] && j <= n)
                {
                    s.pop();
                    j++;
                }
                // PRINT(s);
                // cout << arr[j] << endl;
            }
            // PRINT(s);

            if (!s.empty())
            {
                cout << "No" << endl;
            }
            else
            {
                cout << "Yes" << endl;
            }
        }
        if (x == 0)
        {
            cout << endl;
        }
    }
    return 0;
}
