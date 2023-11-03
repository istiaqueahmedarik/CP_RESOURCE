#include <bits/stdc++.h>
#define int long long
#define float double
#define endl '\n'
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);

using namespace std;
int fact(int n)
{
    if (n == 1)
        return 1;
    return n * fact(n - 1);
}
int32_t main()
{
    IOS;
    int n;
    cin >> n;
    int temp = n * n / 2;
    cout << fact(n) / temp << endl;
    return 0;
}
/*

*/