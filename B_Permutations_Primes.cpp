#include <bits/stdc++.h>
#define int long long
#define float double
#define endl '\n'
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);

using namespace std;
vector<bool> sieve(2000005, true);
void generatePrimes(int n)
{
    sieve[0] = sieve[1] = false;
    for (int i = 2; i * i <= n; i++)
    {
        if (sieve[i])
        {
            for (int j = i * i; j <= n; j += i)
            {
                sieve[j] = false;
            }
        }
    }
}
int MEX(vector<int> &v, int l, int r, int n)
{
    map<int, int> test;
    for (int i = l; i <= r; i++)
    {
        test[v[i]]++;
    }
    int ans = n + 1;
    for (int i = 1; i <= n; i++)
    {
        if (!test[i])
            return i;
    }
    return ans;
}
map<vector<int>, int> mp;
int generator(int n)
{
    int ret = LLONG_MIN;
    mp.clear();
    vector<int> test;
    for (int i = 1; i <= n; i++)
    {
        test.push_back(i);
    }
    int c = 0;
    for (int i = 0; i < test.size(); i++)
    {
        for (int j = i + 1; j < test.size(); j++)
        {
            if (sieve[MEX(test, i, j, n)])
            {
                c++;
            }
        }
    }
    mp[test] = c;
    ret = max(ret, c);
    do
    {
        int c = 0;
        for (int i = 0; i < test.size(); i++)
        {
            for (int j = i + 1; j < test.size(); j++)
            {
                if (sieve[MEX(test, i, j, n)])
                {
                    c++;
                }
            }
        }
        mp[test] = c;
        ret = max(ret, c);
    } while (next_permutation(test.begin(), test.end()));
    return ret;
}
int32_t main()
{
    IOS;
    // generatePrimes(2000005);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        // int mx = generator(n);
        // cout << n << "-->" << endl;
        // for (auto i : mp)
        // {
        //     if (i.second == mx)
        //     {
        //         cout << i.second << "-->" << endl;
        //         for (auto j : i.first)
        //         {
        //             cout << j << " ";
        //         }
        //         cout << endl;
        //     }
        // }
        int x = n / 2;
        if (n == 1)
        {
            cout << 1 << endl;
        }
        else if (n == 2)
            cout << 2 << " " << 1 << endl;
        else
        {
            vector<int> ans(n);
            ans[0] = 2;
            ans[n - 1] = 3;
            int start = 4;
            for (int i = 1; i < n - 1; i++)
            {
                if (i == x)
                {
                    ans[i] = 1;
                    continue;
                }
                ans[i] = start++;
            }
            for (auto &i : ans)
            {
                cout << i << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
/*
    5
    1 2 3 5 4
    1 2
    1 2 3
    1 1
    1 3
    1 5
    1 3 5





*/