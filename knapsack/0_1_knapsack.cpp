#include <bits/stdc++.h>
using namespace std;

int ans(int n, int cap, int wt[], int val[])
{
    if (n == 0 || cap == 0)
        return 0;
    if (wt[n - 1] <= cap)
        return max(val[n - 1] + ans(n - 1, cap - wt[n - 1], wt, val), ans(n - 1, cap, wt, val));
    else
        return ans(n - 1, cap, wt, val);
}

int main()
{
    int n, cap;
    cin >> n >> cap;
    int wt[n], val[n];
    for (int i = 0; i < n; i++)
        cin >> wt[i];
    for (int i = 0; i < n; i++)
        cin >> val[i];
    cout << ans(n, cap, wt, val) << endl;
}