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
    int ans = LLONG_MIN;
    int temp = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i + 1] - arr[i] > k)
        {
            ans = max(ans, temp);
            temp = 0;
        }
        else
            temp++;
    }
    ans = max(ans, temp);
    cout << n - 1 - ans << endl;
}
void simulate()
{
    vector<int> arr(10);
    int n = 10;
    int k = rand() % 100;
    for (int i = 0; i < 10; i++)
    {
        arr[i] = rand() % 100;
    }
    sort(arr.begin(), arr.end());
    int ans = 0, ans1 = 0;
    int start = 0, last = n;
    for (int i = 1; i < last; i++)
    {
        int diff = arr[i] - arr[i - 1];
        if (diff > k)
        {
            if (i - start < last - i)
            {
                ans += i - start;
                start = i;
            }
            else
            {
                ans += last - i;
                last = i;
            }
        }
    }
    start = 0, last = n;
    sort(arr.rbegin(), arr.rend());
    for (int i = 1; i < last; i++)
    {
        int diff = arr[i - 1] - arr[i];
        if (diff > k)
        {
            if (i - start < last - i)
            {
                ans1 += i - start;
                start = i;
            }
            else
            {
                ans1 += last - i;
                last = i;
            }
        }
    }
    if (ans1 < ans)
    {
        cout << "yes" << endl;
        cout << n << " " << k << endl;
        for (auto i : arr)
            cout << i << " ";
        cout << endl;
    }
}
auto main() -> int32_t
{
    IOS;
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}
/*
8 3 1 4 5 10 7 3
0 1 2 3 4 5 6 7
1 3 3 4 5 7 8 10

*/