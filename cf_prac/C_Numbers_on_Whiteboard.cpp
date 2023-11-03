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
        int temp = n;
        vector<pair<int, int>> v;
        int ans = n;
        for (int i = n - 1; i > 0; i--)
        {
            temp = ceil((temp + i) / 2.0);
            v.push_back({i, ans});
            ans = temp;
        }
        cout << temp << endl;
        for (auto i : v)
        {
            cout << i.first << " " << i.second << endl;
        }
    }
    return 0;
}

/*
    1 2 3 4
    1 2 4
    1 3
    2


*/