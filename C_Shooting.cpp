#include <bits/stdc++.h>
using namespace std;
#define int long long
#define float double
#define endl '\n'
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
// decltype
const float pi = 3.141592653589793238462643383279502884197;
const int MOD = 1e9 + 7, dx[] = {1, 0, -1, 0, 1, -1, -1, 1}, dy[] = {0, 1, 0, -1, 1, 1, -1, -1};
void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector<int> ans;
    int total = 0;
    for (int i = 0; i < n; i++)
    {
        bool flag = false;
        int temp = 0;
        for (int j = 1; j < n; j++)
        {
            if (arr[j] > arr[temp])
                temp = j;
        }
        ans.push_back(temp + 1);
        total += i * arr[temp] + 1;
        arr[temp] = 0;
    }
    cout << total << endl;
    for (auto i : ans)
        cout << i << " ";
    cout << endl;
}
auto main() -> int32_t
{
    IOS;
    int t = 1, cs = 1;
    while (t--)
    {
        solve();
    }

    return 0;
}