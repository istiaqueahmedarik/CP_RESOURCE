#include <bits/stdc++.h>
#define int long long
#define float double
#define endl '\n'
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);

using namespace std;

vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
map<int, int> mp;
void pre(int n)
{
    for (int i = 0; i < primes.size(); i++)
    {
        if (n % primes[i] == 0)
        {
            int c = 0;
            while (n % primes[i] == 0)
            {
                c++;
                n /= primes[i];
            }
            mp[primes[i]] += c;
        }
    }
    if (n > 1)
        mp[n]++;
}

int32_t main()
{
    IOS;
    int t;
    cin >> t;
    int cs = 1;
    while (t--)
    {
        mp.clear();
        cout << "Case " << cs++ << ": ";
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++)
            pre(i);
        int first = 0;
        cout << n << " = ";
        for (auto i : mp)
        {
            if (first)
                cout << "* ";
            first = 1;
            cout << i.first << " (" << i.second << ") ";
        }
        cout << endl;
    }
    return 0;
}