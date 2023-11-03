#include <bits/stdc++.h>
using namespace std;
double POW(double mid, double x)
{
    double ans = 1.0;
    for (int i = 0; i < x; i++)
    {
        ans *= mid;
    }
    return ans;
}
int main()
{
    int n, x;
    cin >> n >> x;
    double low = 1, high = n, eps = 1e-6, mid;
    while (high - low > eps)
    {
        mid = (low + high) / 2;
        if (POW(mid, x) < n)
        {
            low = mid;
        }
        else
        {
            high = mid;
        }
    }
    cout << fixed << setprecision(5) << low << endl;
}