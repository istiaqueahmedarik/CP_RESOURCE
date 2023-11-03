t = int(input())

for i in range(t):
    n = int(input())
    arr = list(map(int, input().split()))
    c = 0
    for j in range(n):
        for k in range(i+1, n):
            if arr[j]+arr[k] == arr[j]*arr[k]:
                c += 1
    print(c//2)
