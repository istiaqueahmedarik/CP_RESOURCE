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

class NCR
{
    int N, mod;
    vector<int> factorialNumInverse, naturalNumInverse, fact;
    void InverseofNumber(int p)
    {
        naturalNumInverse[0] = naturalNumInverse[1] = 1;
        for (int i = 2; i <= N; i++)
            naturalNumInverse[i] = naturalNumInverse[p % i] * (p - p / i) % p;
    }
    void InverseofFactorial(int p)
    {
        factorialNumInverse[0] = factorialNumInverse[1] = 1;

        for (int i = 2; i <= N; i++)
            factorialNumInverse[i] = (naturalNumInverse[i] * factorialNumInverse[i - 1]) % p;
    }
    void factorial(int p)
    {
        fact[0] = 1;

        for (int i = 1; i <= N; i++)
        {
            fact[i] = (fact[i - 1] * i) % p;
        }
    }

public:
    NCR(int N, int mod)
    {
        this->N = N;
        this->mod = mod;
        factorialNumInverse.resize(N + 1);
        naturalNumInverse.resize(N + 1);
        fact.resize(N + 1);
        InverseofNumber(mod);
        InverseofFactorial(mod);
        factorial(mod);
    }
    int nCr(int N, int R, int p)
    {
        int ans = ((fact[N] * factorialNumInverse[R]) % p * factorialNumInverse[N - R]) % p;
        return ans;
    }
};

inline void
solve()
{
    NCR comb(2000005, MOD);
    int h, w, n;
    cin >> h >> w >> n;
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        v.emplace_back(x, y);
    }
    v.emplace_back(h, w);
    n++;
    sort(all(v));
    vector<int> dp(n + 1, 0);

    for (int i = 0; i < n; i++)
    {
        dp[i] = comb.nCr(v[i].first - 1 + v[i].second - 1, v[i].first - 1, MOD);
        for (int j = 0; j < i; j++)
        {
            // up
            if (v[i].second < v[j].second)
                continue;
            int notGo = comb.nCr(v[i].first + v[i].second - v[j].first - v[j].second, v[i].first - v[j].first, MOD);
            dp[i] = (dp[i] - (notGo * 1LL * dp[j]) % MOD + MOD) % MOD;
        }
    }
    cout << dp[n - 1] << endl;
}

auto main() -> int32_t
{
    IOS;
    int t = 1, cs = 1;
    while (t--)
    {
        solve();
    }

    return 0;
}