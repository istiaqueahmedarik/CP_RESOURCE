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
        int n, k;
        cin >> n >> k;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        sort(arr.begin(), arr.end());
        int c = 0;
        for (int i = 0; i < n - 2 * k; i++)
            c += arr[i];
        for (int i = n - 2 * k; i < n;)
        {
            int cnt = 0;
            int j = i;
            for (; i < n;)
            {
                if (arr[j] == arr[i])
                    cnt++, i++;
                else
                    break;
            }
            if (cnt > k)
                c += cnt - k;
        }
        cout << c << endl;
    }
    return 0;
}
/*
    1 10 10 1 10 2 7 10 3
    1 1 2 3 7 10 10 10 10

*/