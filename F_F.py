t = int(input())
for _ in range(t):
    n, m = map(int, input().split())
    ans = 0
    for i in range(n):
        ans += (i+1)**(i+1)
    print(ans % m)
