#include <bits/stdc++.h>
#define int long long
#define float double
#define endl '\n'
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);

using namespace std;
bool prime[10005];
void init()
{
    for (int i = 0; i < 10005; i++)
        prime[i] = true;
    prime[0] = prime[1] = false;
    for (int i = 2; i <= 10000; i++)
    {
        if (prime[i])
        {
            for (int j = 2 * i; j <= 10000; j += i)
            {
                prime[j] = false;
            }
        }
    }
}
int32_t main()
{
    IOS;
    init();
    int n;
    cin >> n;
    for (int i = 0; i <= n; i++)
    {
        if (prime[i])
        {
            cout << i << " ";
        }
    }
    cout << endl;
    return 0;
}