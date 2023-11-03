#include <bits/stdc++.h>
#define int long long
#define float double
#define endl '\n'
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);

using namespace std;
bool powOfTwo(int n) { return n && !(n & (n - 1)); }
unordered_map<int, int> solve1(int n, int k, unordered_map<int, int> &ans)
{
    unordered_map<int, bool> visited;
    ans[n - 1] = 0;
    visited[0] = visited[n - 1] = 1;
    ans[1] = (n / 2) - 1;
    visited[(n / 2) - 1] = visited[1] = 1;
    for (int i = 0; i <= n - 1; i++)
    {
        if (visited[i] || powOfTwo(i))
            continue;
        bitset<17> bits(i);
        bitset<17> ConBits(0);
        for (int j = 0; j <= log2(n) - 1; j++)
            if (!bits[j])
                ConBits[j] = 1;
        int cnt = 0, lsb = 1;
        for (int j = 0; j <= log2(n) - 1; j++)
        {
            if (ConBits[j])
                cnt += lsb;
            lsb *= 2;
        }
        if (!powOfTwo(cnt) && !visited[cnt])
        {
            ans[i] = cnt;
            visited[i] = visited[cnt] = 1;
        }
    }
    int remain = 2;
    while (remain < n)
    {
        ans[remain] = n - 1 - remain / 2;
        remain *= 2;
    }
    return ans;
}
unordered_map<int, int> solve2(int n, int k, unordered_map<int, int> &ans)
{
    unordered_map<int, bool> visited;
    ans[n - 1] = k;
    visited[n - 1] = visited[k] = 1;
    for (int i = 0; i <= n - 1; i++)
    {
        if (visited[i])
            continue;
        bitset<17> bits(i);
        bitset<17> ConBits(0);
        for (int j = 0; j <= log2(n) - 1; j++)
            if (!bits[j])
                ConBits[j] = 1;
        int cnt = 0, lsb = 1;
        for (int j = 0; j <= log2(n) - 1; j++)
        {
            if (ConBits[j])
                cnt += lsb;
            lsb *= 2;
        }
        if (!visited[cnt])
        {
            ans[i] = cnt;
            visited[i] = visited[cnt] = 1;
        }
    }
    for (int i = 1; i <= n - 1; i++)
    {
        if (!visited[i])
        {
            ans[0] = i;
            break;
        }
    }
    return ans;
}
unordered_map<int, int> ans(int n, int k)
{
    unordered_map<int, int> ans;
    if (n == 4 && k == 3)
        return ans;
    if (k == n - 1)
        return solve1(n, k, ans);
    return solve2(n, k, ans);
}
int32_t main()
{
    IOS;
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        unordered_map<int, int> final = ans(n, k);
        if (final.size())
        {
            for (auto i : final)
            {
                cout << i.first << " " << i.second << endl;
            }
        }
        else
            cout << -1 << endl;
    }
    return 0;
}