#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
int solve2(int n)
{
    if (n >= 2 && n <= 9)
    {
        return 1;
    }
    else if (n >= 10 && n <= 81)
    {
        return 0;
    }
    else if (n >= 82 && n <= 729)
    {
        return 1;
    }
    else if (n >= 730 && n <= 6561)
    {
        return 0;
    }
    else if (n >= 6562 && n <= 59049)
    {
        return 1;
    }
    else if (n >= 59050 && n <= 531441)
    {
        return 0;
    }
    else if (n >= 531442 && n <= 4782969)
    {
        return 1;
    }
    else if (n >= 4782970 && n <= 43046721)
    {
        return 0;
    }
    else if (n >= 43046722 && n <= 387420489)
    {
        return 1;
    }
    else if (n >= 387420490 && n <= 3486784401)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int qp(int a, int b)
{
    int x = 1;
    a %= MOD;
    while (b)
    {
        if (b & 1)
            x = x * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return x;
}
int solve1(int n)
{
    int nines = 0, twoes = 0;
    int st = 0;
    int prev = 0;
    int cur = 0;
    for (;;)
    {
        int sz = qp(9, nines) * qp(2, twoes);
        if (sz >= n && n >= prev)
        {
            if (st)
            {
                return 1;
            }
            else
            {
                return 0;
            }
            break;
        }
        st ^= 1;
        prev = sz;
        if (nines == twoes)
            nines++;
        else
            twoes++;
    }
}

auto main() -> int32_t
{
    // IOS;
    for (int i = 1; i <= 100; i++)
    {
        if (solve1(i) != solve2(i))
        {
            cout << i << endl;
        }
    }

    return 0;
}
