#include <bits/stdc++.h>
#define int long long
#define float double
#define endl '\n'
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);

using namespace std;
void print(vector<int> &v)
{
    for (auto i : v)
    {
        cout << i << " ";
    }
    cout << endl;
}
int32_t main()
{
    IOS;
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        if (arr.back() == 1)
        {
            cout << "NO" << endl;
            continue;
        }
        cout << "YES" << endl;
        vector<int> ans;
        while (n--)
        {
            for (int j = 0; j < arr.size(); j++)
            {
                if (arr[j])
                    arr[j] = 0;
                else
                {
                    arr.erase(arr.begin() + j);
                    ans.push_back(j);
                    break;
                    // print(arr);
                }
            }
        }
        for (int i = ans.size() - 1; i >= 0; i--)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}