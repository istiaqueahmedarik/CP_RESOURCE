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
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr.begin(), arr.end());
    vector<int> cons;
    int temp = 1;-
    int start = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (start + 1 == arr[i])
            temp++;
        else
        {
            cons.push_back(temp);
            temp = 0;
        }
    }
    if (temp)
        cons.push_back(temp);
    for (int temp = 1;; temp++)
    {

    }
}
auto main() -> int32_t
{
    IOS;
    int t, cs = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}

/*
 2 3  5 6  8 9 10 11

*/