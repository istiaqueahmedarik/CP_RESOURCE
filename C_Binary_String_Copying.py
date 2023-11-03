def solve():
    n, m = map(int, input().split())
    s = input().strip()
    pref = [0] * (n + 1)

    for i in range(1, n + 1):
        if s[i - 1] == '1':
            pref[i] = pref[i - 1] + 1
        else:
            pref[i] = pref[i - 1]

    st = set()
    for _ in range(m):
        l, r = map(int, input().split())
        temp = s[:l - 1]
        x = pref[r] - pref[l - 1]
        len_x = r - l + 1
        temp += '0' * (len_x - x)
        temp += '1' * x
        temp += s[r:]
        st.add(temp)

    print(len(st))


def main():
    t = int(input())
    for _ in range(t):
        solve()


if __name__ == "__main__":
    main()
