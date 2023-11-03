/*
╦┌─┐┌┬┐┬┌─┐┬ ┬┌─┐  ╔═╗┬ ┬┌┬┐┌─┐┌┬┐  ╔═╗┬─┐┬┬┌─
║└─┐ │ │├─┤│ │├┤   ╠═╣├─┤│││├┤  ││  ╠═╣├┬┘│├┴┐
╩└─┘ ┴ ┴┴ ┴└─┘└─┘  ╩ ╩┴ ┴┴ ┴└─┘─┴┘  ╩ ╩┴└─┴┴ ┴
*/

#include <bits/stdc++.h>
using namespace std;
void __print(int x) { cerr << x; }
#define int long long
#define pi acos(-1)
#define endl '\n'
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
#define FileIO                        \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout)

/// debug
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

/// PBDS
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// template <typename T>
// using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// template <typename T>
// using o_set_g = tree<T, null_type, greater<T>, rb_tree_tag, tree_order_statistics_node_update>;
// template <typename T>
// using o_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
// template <typename T>
// using o_multiset_g = tree<T, null_type, greater_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

/// decltype and const
const int MOD = 1e9 + 7, dx[] = {1, 0, -1, 0, 1, -1, -1, 1}, dy[] = {0, 1, 0, -1, 1, 1, -1, -1};

/// useful function
// bitmask
/*  void all_subset(vector<int>&arr,int n){for (int i = 0; i < (1 << n); i++){for (int j = 0; j < n; j++){if (i & (1 << j))cout << arr[j] << " ";}cout << endl;}} void clr_last(int &N,int i){N = (N & ~(1<<(i+1) - 1));} void clr_first(int &N,int i){N = (N & (1<<(i+1) - 1));} int ith_bit(int n,int i){return (n >> i) & 1;} void set(int &n,int i){n |= (1<<i);} void clr(int &n,int i){n &= ~(1 << i);} void toggle(int &n,int i){n ^= ( 1<< i );}*/
// Number_Theory
/*int bigPow(int x, int n) { int res = 1;while (n){if (n & 1)res *= x;x *= x;n >>= 1;}return res;} vector<int> primes,lp(1000000, 0), hp(1000000, 0);vector<bool> sieve(1000000, true); void generatePrimes(int n) {sieve[0] = sieve[1] = false;for(int i = 2; i * i <= n; i++){if (sieve[i]){lp[i] = hp[i] = i;for (int j = i * i; j <= n; j += i){sieve[j] = false;hp[j] = i;
if (lp[j] == 0)lp[j] = i;}}}for (int i = 2; i <= n; i++){if (sieve[i]){primes.push_back(i);}}}map<int,int> prime_factor(int x){//generate prime firstmap<int, int> mp;while (x > 1){int prime_factor = hp[x];while (x % prime_factor == 0){mp[prime_factor]++;x /= prime_factor;}}return mp;}
 */

void solve()
{
}

auto main() -> int32_t
{
    IOS;
    int t, cs = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}