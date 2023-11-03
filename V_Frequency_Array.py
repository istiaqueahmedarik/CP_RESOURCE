n, m = map(int, input().split())
arr = list(map(int, input().split()))

mp = {}

for i in arr:
    if i in mp:
        mp[i] += 1
    else:
        mp[i] = 1
for i in range(1, m+1):
    if i not in mp:
        print(0)
    else:
        print(mp[i])
