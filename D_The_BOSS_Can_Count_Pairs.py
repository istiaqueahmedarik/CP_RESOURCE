t = int(input())
for i in range(t):
    n = int(input())
    lst = list(map(int, input().split()))
    lst1 = list(map(int, input().split()))
    lst.sort()
    lst1.sort()
    ans = 0
    for i in range(n):
        for j in range(i+1, n):
            if (lst[i]*lst[j] == lst1[i]+lst1[j]):
                ans += 1
    print(ans)
