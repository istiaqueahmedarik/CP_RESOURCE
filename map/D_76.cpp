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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    map<int, int> mp;
    set<int> ones;
    for (int i = 0; i < n; i++)
    {
        mp[a[i]]++;
        if (mp[a[i]] == 1)
            ones.insert(a[i]);
        else
        {
            ones.erase(a[i]);
        }
        if (i < k - 1)
            continue;
        int next_element = a[i - k];
        mp[next_element]--;
        if (mp[next_element] == 1)
            ones.insert(next_element);
        else
            ones.erase(next_element);
        if (ones.empty())
        {
            cout << "Nothing" << endl;
        }
        else
        {
            cout << *ones.rbegin() << endl;
        }
    }

    return 0;
}