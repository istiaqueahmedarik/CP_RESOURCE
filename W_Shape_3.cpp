#include <bits/stdc++.h>
#define int long long
#define float double
#define endl '\n'
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);

using namespace std;
void space(int n)
{
    if (n <= 0)
        return;
    cout << " ";
    space(n - 1);
}
void star(int n)
{
    if (n <= 0)
        return;
    cout << "*";
    star(n - 1);
}
void pattern(int n, int i)
{
    if (n == 0)
        return;
    space(n - 1);
    star(i);
    star(i - 1);
    cout << endl;
    pattern(n - 1, i + 1);
    space(n - 1);
    star(i);
    star(i - 1);
    cout << endl;
}
int32_t main()
{
    // IOS;
    int n;
    cin >> n;
    pattern(n, 1);
    return 0;
}