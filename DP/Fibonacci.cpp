#include <bits/stdc++.h>
using namespace std;
long long dp[100000000];
void fibo(long long n)
{
    dp[0] = 0;
    dp[1] = 1;
    for (long long i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
}
int main()
{
    long long n;
    cin >> n;
    fibo(n);
    cout << dp[n] << endl;
}