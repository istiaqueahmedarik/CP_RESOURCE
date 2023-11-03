#include <bits/stdc++.h>
using namespace std;
int ans(int n)
{
    if (n == 1)
        return 0;
    if (n == 2)
        return 1;
    if (n == 3)
        return 1;
    int temp1 = n % 2 ? INT_MAX : n / 2;
    int temp2 = n % 3 ? INT_MAX : n / 3;
    return 1 + ans(min({n - 1, temp1, temp2}));
}
int main()
{
    int n;
    cin >> n;
    cout << ans(n) << endl;
}
