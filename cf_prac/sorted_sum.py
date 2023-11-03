

ans = 0
a = [1,2,3,4,5]
temp = [0]*len(a)
n = len(a)
temp2 = [i for i in range(1,len(a)+1)]
for i in range(len(a)):
    for j in range(n-i):
        temp[j+i]+=a[i]*temp2[j]

for i in temp:
    ans+=i
    ans = ans%1000000007
print(ans)

