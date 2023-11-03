#include <bits/stdc++.h>
#define int long long
#define float double
#define endl '\n'
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);

using namespace std;
vector<int> primes;
bool isPrime[1000000];
void pre()
{
    isPrime[0] = isPrime[1] = 1;
    for (int i = 2; i < 1000000; i += 2)
    {
        if (isPrime[i] == 0)
        {
            primes.push_back(i);
            for (int j = i * i; j < 1000000; j += i)
            {
                isPrime[j] = 1;
            }
        }
        if (i == 2)
            i--;
    }
}
int divisors(int n)
{
    int c = 1;
    for (int i = 0; i < primes.size() && primes[i] * primes[i] <= n; i++)
    {
        if (n % primes[i] == 0)
        {
            int temp = 0;
            while (n % primes[i] == 0)
            {
                temp++;
                n /= primes[i];
            }
            c *= (temp + 1);
        }
    }
    if (n > 1)
        c *= 2;
    return c;
}
int32_t main()
{
    IOS;
    pre();
    int t;
    cin >> t;
    int cs = 1;
    while (t--)
    {
        cout << "Case " << cs++ << ": ";
        int n;
        cin >> n;
        cout << divisors(n) - 1 << endl;
    }
    return 0;
}