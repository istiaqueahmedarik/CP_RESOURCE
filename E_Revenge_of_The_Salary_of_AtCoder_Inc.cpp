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
const int MOD = 998244353, dx[] = {1, 0, -1, 0, 1, -1, -1, 1}, dy[] = {0, 1, 0, -1, 1, 1, -1, -1};
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

inline int32_t modinv_nocheck(int32_t value, int32_t MOD)
{
    assert(0 <= value and value < MOD);
    if (value == 0)
        return -1;
    int64_t a = value, b = MOD;
    int64_t x = 0, y = 1;
    for (int64_t u = 1, v = 0; a;)
    {
        int64_t q = b / a;
        x -= q * u;
        std::swap(x, u);
        y -= q * v;
        std::swap(y, v);
        b -= q * a;
        std::swap(b, a);
    }
    if (not(value * x + MOD * y == b and b == 1))
        return -1;
    if (x < 0)
        x += MOD;
    assert(0 <= x and x < MOD);
    return x;
}
inline int32_t modpow(uint_fast64_t x, uint64_t k, int32_t MOD)
{
    assert(/* 0 <= x and */ x < (uint_fast64_t)MOD);
    uint_fast64_t y = 1;
    for (; k; k >>= 1)
    {
        if (k & 1)
            (y *= x) %= MOD;
        (x *= x) %= MOD;
    }
    assert(/* 0 <= y and */ y < (uint_fast64_t)MOD);
    return y;
}
inline int32_t modinv(int32_t x, int32_t MOD)
{
    int32_t y = modinv_nocheck(x, MOD);
    assert(y != -1);
    return y;
}
template <int32_t MOD>
struct mint
{
    int32_t value;
    mint() : value() {}
    mint(int64_t value_) : value(value_ < 0 ? value_ % MOD + MOD : value_ >= MOD ? value_ % MOD
                                                                                 : value_) {}
    mint(int32_t value_, std::nullptr_t) : value(value_) {}
    explicit operator bool() const { return value; }
    inline mint<MOD> operator+(mint<MOD> other) const { return mint<MOD>(*this) += other; }
    inline mint<MOD> operator-(mint<MOD> other) const { return mint<MOD>(*this) -= other; }
    inline mint<MOD> operator*(mint<MOD> other) const { return mint<MOD>(*this) *= other; }
    inline mint<MOD> &operator+=(mint<MOD> other)
    {
        this->value += other.value;
        if (this->value >= MOD)
            this->value -= MOD;
        return *this;
    }
    inline mint<MOD> &operator-=(mint<MOD> other)
    {
        this->value -= other.value;
        if (this->value < 0)
            this->value += MOD;
        return *this;
    }
    inline mint<MOD> &operator*=(mint<MOD> other)
    {
        this->value = (uint_fast64_t)this->value * other.value % MOD;
        return *this;
    }
    inline mint<MOD> operator-() const { return mint<MOD>(this->value ? MOD - this->value : 0, nullptr); }
    inline bool operator==(mint<MOD> other) const { return value == other.value; }
    inline bool operator!=(mint<MOD> other) const { return value != other.value; }
    inline mint<MOD> pow(uint64_t k) const { return mint<MOD>(modpow(value, k, MOD), nullptr); }
    inline mint<MOD> inv() const { return mint<MOD>(modinv(value, MOD), nullptr); }
    inline mint<MOD> operator/(mint<MOD> other) const { return *this * other.inv(); }
    inline mint<MOD> &operator/=(mint<MOD> other) { return *this *= other.inv(); }
};
template <int32_t MOD>
mint<MOD> operator+(int64_t value, mint<MOD> n) { return mint<MOD>(value) + n; }
template <int32_t MOD>
mint<MOD> operator-(int64_t value, mint<MOD> n) { return mint<MOD>(value) - n; }
template <int32_t MOD>
mint<MOD> operator*(int64_t value, mint<MOD> n) { return mint<MOD>(value) * n; }
template <int32_t MOD>
mint<MOD> operator/(int64_t value, mint<MOD> n) { return mint<MOD>(value) / n; }
template <int32_t MOD>
std::istream &operator>>(std::istream &in, mint<MOD> &n)
{
    int64_t value;
    in >> value;
    n = value;
    return in;
}
template <int32_t MOD>
std::ostream &operator<<(std::ostream &out, mint<MOD> n) { return out << n.value; }

inline void solve()
{
    int n;
    cin >> n;
    vector<mint<MOD>> arr(n);
    for (mint<MOD> &x : arr)
        cin >> x;
    mint<MOD> ans = 0;
    mint<MOD> cur = modinv(n, MOD);
    for (auto i : arr)
    {
        ans += i.value * cur;
        cur *= (n + 1);
        cur *= modinv(n, MOD);
    }
    cout << ans << endl;
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