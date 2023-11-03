#include <bits/stdc++.h>
#define int long long
#define float double
#define endl '\n'
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);

using namespace std;
int getSum(int n)
{
    int sum = 0;
    while (n != 0)
    {
        sum = sum + n % 10;
        n = n / 10;
    }
    return sum;
}
int32_t main()
{
    IOS;
    int t;
    cin >> t;
    while (t--)
    {
        set<int> digits;
        int n, q;
        cin >> n >> q;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            arr[i] = x;
            if (x >= 10)
            {
                digits.insert(i);
            }
        }
        while (q--)
        {
            int choice;
            cin >> choice;
            if (choice == 2)
            {
                int x;
                cin >> x;
                cout << arr[--x] << endl;
            }
            else
            {
                int l, r;
                cin >> l >> r;
                l--;
                r--;
                if (digits.empty())
                    continue;
                auto it = digits.lower_bound(l);
                vector<int> v;
                for (; it != digits.end(); it++)
                {
                    if (*it > r)
                    {
                        break;
                    }
                    arr[*it] = getSum(arr[*it]);
                    if (arr[*it] < 10)
                    {
                        v.push_back(*it);
                    }
                }
                for (auto i : v)
                {
                    digits.erase(i);
                }
            }
        }
    }
    return 0;
}