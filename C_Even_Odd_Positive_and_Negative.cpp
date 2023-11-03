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
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    int even = 0, odd = 0, pos = 0, neg = 0;
    for (int i = 0; i < n; i++)
    {
        if (v[i] % 2 == 0)
            even++;
        else
            odd++;
        if (v[i] > 0)
            pos++;
        else if (v[i] < 0)
            neg++;
    }
    cout << "Even: " << even << endl;
    cout << "Odd: " << odd << endl;
    cout << "Positive: " << pos << endl;
    cout << "Negative: " << neg << endl;
    return 0;
}