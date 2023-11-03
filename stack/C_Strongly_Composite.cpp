#include <bits/stdc++.h>
#define int long long
#define float double
#define endl '\n'
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);

using namespace std;
const int N = 1e7 + 7;
vector<int> divisors[N];
int Count[N];
const int N = 2e5 + 7;
bool prime[N];
vector<int> v[N];

bool checker(int n)
{
    int c = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            if (v[i][j] + i - 1 > n)
            {
                break;
            }
            if (v[i][j] + i - 1 <= n)
            {
                if (!prime[v[i][j] + i - 1])
                {
                    c++;
                    prime[v[i][j] + i - 1] = 1;
                }
            }
        }
        if (c > Count[n])
            return false;
    }
    if (c == Count[n])
        return true;
    else
        return false;
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
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        }
    return 0;
}
