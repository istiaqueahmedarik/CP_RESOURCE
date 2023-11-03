#include <bits/stdc++.h>
using namespace std;

vector<int> prime(int n)
{
    vector<int> primes;
    primes.push_back(2);
    int num = 3;
    while (primes.size() < n)
    {
        bool isPrime = true;
        for (int p : primes)
        {
            if (num % p == 0)
            {
                isPrime = false;
                break;
            }
        }
        if (isPrime)
        {
            primes.push_back(num);
        }
        num += 2;
    }
    return primes;
}

void solve(int t, vector<int> coins)
{
    for (int i = 0; i < t; i++)
    {
        int c = coins[i];
        vector<int> primes_list = prime(c / 2 + 1);
        cout << c / 2 << "\n";
        for (int j = 0; j < c / 2; j++)
        {
            cout << primes_list[j] << " ";
        }
        cout << "\n1\n";
    }
}

int main()
{
    int t = 1;
    cin >> t;
    vector<int> coins = {8};
    solve(t, coins);
    return 0;
}
