N = 2023
dp = [[0 for i in range(N)] for j in range(N)]
rm = [0 for i in range((N + 1) * (N + 2) // 2)]


def init():
    c = 1
    for i in range(N):
        for j in range(i + 1):
            rm[c] = (i, j)
            dp[i][j] = c**2

            if i > 0:
                dp[i][j] += dp[i - 1][j]
                if j > 0:
                    dp[i][j] += dp[i - 1][j - 1]
                    if i > 1:
                        dp[i][j] -= dp[i - 2][j - 1]
            c += 1


def solve():
    n = int(input())
    x, y = rm[n]
    print(dp[x][y])


def main():
    init()

    t = int(input())
    for _ in range(t):
        solve()

main()