import itertools
import math

def is_square(n):
    return math.isqrt(n)**2 == n

def solve(n):
    digits = '123456789'
    for p in itertools.permutations(digits, n):
        num = int(''.join(p))
        if is_square(num):
            print(num)
    print(-1)

solve(5)