#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

void f()
{
    int n, k;
    cin >> n >> k;
    int a[n];
    vector<int> b;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        b.push_back(x);
    }
    sort(b.begin(), b.end());
    for (int i = 0; i < n; i++)
    {
        int x = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
        int y = upper_bound(b.begin(), b.end(), a[i]) - b.begin();
        int ans;
        if (abs(k - b[x]) < abs(b[y] - k))
            ans = x;
        else
            ans = y;
        cout << b[ans] << ' ';
        b.erase(b.begin() + ans);
    }
    cout << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1, tc = 1;
    cin >> t;
    while (t--)
    {
        // cout << "Case " << tc++ << ':' << endl;
        f();
    }
}