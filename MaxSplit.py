inp = input()

ans = []
L = R = 0
prev = 0
for i in range(len(inp)):
    if (inp[i] == 'L'):
        L += 1
    else:
        R += 1
    if (L == R):
        ans.append(inp[prev:i+1])
        L = R = 0
        prev = i+1
print(len(ans))
for i in ans:
    print(i)
