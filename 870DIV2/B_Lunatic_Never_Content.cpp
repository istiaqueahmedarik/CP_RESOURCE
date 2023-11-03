#include <bits/stdc++.h>
#define int long long
#define float double
#define endl '\n'
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);

using namespace std;
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
int lcm(int a, int b)
{
    return (a * b) / gcd(a, b);
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
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        int diff = 0;
        vector<int> v;
        for (int i = 0; i < n / 2; i++)
        {

            if (arr[i] == arr[n - i - 1])
                continue;
            int temp = abs(arr[i] - arr[n - i - 1]);
            arr[i] = gcd(arr[i], arr[n - i - 1]);
            arr[n - i - 1] = gcd(arr[i], arr[n - i - 1]);
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        cout << ans << endl;
    }
    return 0;
}