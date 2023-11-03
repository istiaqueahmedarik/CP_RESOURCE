/*******************************************
 @b |I|s|t|i|a|q|u|e| |A|h|m|e|d| |A|r|i|k|
********************************************/
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
void __print(int x) { cerr << x; }
#define int long long
#define pi acos(-1)
#define endl '\n'
#define set_bits __builtin_popcountll
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
#define FileIO                        \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout)
///@b decltype and const
const int MOD = 1e9 + 7, dx[] = {1, 0, -1, 0, 1, -1, -1, 1}, dy[] = {0, 1, 0, -1, 1, 1, -1, -1};
///@b debug
struct _
{
    ios_base::Init i;
    _()
    {
        cin.sync_with_stdio(0);
        cin.tie(0);
        cout << fixed << setprecision(10);
    }
} ___;
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }

template <typename T, typename V>
void __print(const pair<T, V> &x)
{
    cerr << '{';
    __print(x.first);
    cerr << ',';
    __print(x.second);
    cerr << '}';
}
template <typename T>
void __print(const T &x)
{
    int f = 0;
    cerr << '{';
    for (auto &i : x)
        cerr << (f++ ? "," : ""), __print(i);
    cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v)
{
    __print(t);
    if (sizeof...(v))
        cerr << ", ";
    _print(v...);
}
#ifndef ONLINE_JUDGE
#define debug(x...)               \
    cerr << "[" << #x << "] = ["; \
    _print(x)
#else
#define debug(x...)
#endif

///@b PBDS
// template <typename T>
// using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// template <typename T>
// using o_set_g = tree<T, null_type, greater<T>, rb_tree_tag, tree_order_statistics_node_update>;
// template <typename T>
// using o_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
// template <typename T>
// using o_multiset_g = tree<T, null_type, greater_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
int bigPow(int x, int n)
{
    int res = 1;
    while (n)
    {
        if (n & 1)
            res *= x;
        x *= x;
        n >>= 1;
    }
    return res;
}
vector<int> primes, lp(1000000, 0), hp(1000000, 0);
vector<bool> sieve(1000000, true);
void generatePrimes(int n)
{
    sieve[0] = sieve[1] = false;
    for (int i = 2; i * i <= n; i++)
    {
        if (sieve[i])
        {
            lp[i] = hp[i] = i;
            for (int j = i * i; j <= n; j += i)
            {
                sieve[j] = false;
                hp[j] = i;
                if (lp[j] == 0)
                    lp[j] = i;
            }
        }
    }
    for (int i = 2; i <= n; i++)
    {
        if (sieve[i])
        {
            primes.push_back(i);
        }
    }
}
map<int, int> prime_factor(int x)
{
    map<int, int> mp;
    while (x > 1)
    {
        int prime_factor = hp[x];
        while (x % prime_factor == 0)
        {
            mp[prime_factor]++;
            x /= prime_factor;
        }
    }
    return mp;
}

inline void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &i : v)
        cin >> i;
    unordered_map<int, int> mp;
    for (auto i : v)
    {
        map<int, int> pf = prime_factor(i);
        for (auto j : pf)
        {
            if (j.second % n)
            {
                cout << "NO\n";
                return;
            }
        }
    }
    cout << "YES\n";
}

auto main() -> int32_t
{
    IOS;
    int t, cs = 1;
    cin >> t;
    generatePrimes(1000000);
    while (t--)
    {
        solve();
    }

    return 0;
}

/*
100 50 10 2 1
100 -> 100 50 25 10 5 4 2 1
50 -> 50 25 10 5 4 2 1
10 -> 10 5 4 2 1
2 -> 2 1
1 -> 1

100 1


*/