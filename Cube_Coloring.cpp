#include <bits/stdc++.h>
using namespace std;

long long dp[7][7][7][7][7][7];
int cnt[100];
int fact[10], inv[10];

int power(int a, int b, int mod)
{
    int res = 1;
    while (b)
    {
        if (b & 1)
            res = (res * 1ll * a) % mod;
        a = (a * 1ll * a) % mod;
        b >>= 1;
    }
    return res;
}

int main()
{
    fact[0] = inv[0] = 1;
    for (int i = 1; i <= 6; ++i)
    {
        fact[i] = (fact[i - 1] * 1ll * i) % 1000000007;
        inv[i] = power(fact[i], 1000000007 - 2, 1000000007);
    }
    dp[0][0][0][0][0][0] = 1;
    for (int a = 0; a <= 6; ++a)
    {
        for (int b = 0; b <= a; ++b)
        {
            for (int c = 0; c <= b; ++c)
            {
                for (int d = 0; d <= c; ++d)
                {
                    for (int e = 0; e <= d; ++e)
                    {
                        for (int f = 0; f <= e; ++f)
                        {
                            int ways = dp[a][b][c][d][e][f];
                            if (a < 6)
                                dp[a + 1][b][c][d][e][f] += ways, dp[a + 1][b][c][d][e][f] %= 1000000007;
                            if (b < a)
                                dp[a][b + 1][c][d][e][f] += ways, dp[a][b + 1][c][d][e][f] %= 1000000007;
                            if (c < b)
                                dp[a][b][c + 1][d][e][f] += ways, dp[a][b][c + 1][d][e][f] %= 1000000007;
                            if (d < c)
                                dp[a][b][c][d + 1][e][f] += ways, dp[a][b][c][d + 1][e][f] %= 1000000007;
                            if (e < d)
                                dp[a][b][c][d][e + 1][f] += ways, dp[a][b][c][d][e + 1][f] %= 1000000007;
                            if (f < e)
                                dp[a][b][c][d][e][f + 1] += ways, dp[a][b][c][d][e]
                                                                    [f + 1] %= 1000000007;
                        }
                    }
                }
            }
        }
    }
    int t;
    cin >> t;
    while (t--)
    {
        memset(cnt, 0, sizeof cnt);
        for (int i = 0; i < 6; ++i)
        {
            char c;
            cin >> c;
            ++cnt[c - 'A'];
            // cout << cnt[c - 'A'] << " ";
        }
        sort(cnt, cnt + 6);
        cout << (dp[cnt[5]][cnt[4]][cnt[3]][cnt[2]][cnt[1]][cnt[0]] *
                 fact[cnt[5]] %
                 (inv[cnt[4]] * inv[cnt[3]] %
                  (inv[cnt[2]] * inv[cnt[1]] %
                   (inv[cnt[0]])))) %
                    (1000000007)
             << "\n";
    }
}
