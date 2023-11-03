n = int(input())

arr = list(map(int, input().split()))

mp = {}

unique = set(arr)

for i in range(n):
    if (arr[i] in mp):
        mp[arr[i]] += 1
    else:
        mp[arr[i]] = 1
ans = 0
for j in unique:
    if (mp[j] > j):
        ans += mp[j]-j
    elif (mp[j] < j):
        ans += mp[j]
print(ans)
