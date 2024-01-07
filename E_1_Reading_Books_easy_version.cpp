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

struct book
{
    int time, alex, bob;
    book(int t, int a, int b)
    {
        time = t;
        alex = a;
        bob = b;
    }
};

inline void solve()
{
    int n, k;
    cin >> n >> k;
    vector<book> v, v1, v2;
    for (int i = 0; i < n; i++)
    {
        int t, a, b;
        cin >> t >> a >> b;
        if (a == 0 && b == 0)
            continue;
        if (a == 1 && b == 1)
            v.push_back(book(t, a, b));
        else if (a == 1 && b == 0)
            v1.push_back(book(t, a, b));
        else if (a == 0 && b == 1)
            v2.push_back(book(t, a, b));
    }
    sort(rall(v), [](book a, book b)
         { return a.time < b.time; });
    sort(rall(v1), [](book a, book b)
         { return a.time < b.time; });
    sort(rall(v2), [](book a, book b)
         { return a.time < b.time; });
    if (min(v1.size(), v2.size()) + v.size() < k)
    {
        cout << -1 << endl;
        return;
    }
    int ans = 0;
    while (k)
    {
        if (v1.empty() || v2.empty())
        {
            ans += v.back().time;
            v.pop_back();
            k--;
            continue;
        }
        if (v.empty())
        {
            ans += v1.back().time + v2.back().time;
            v1.pop_back();
            v2.pop_back();
            k--;
            continue;
        }
        if (v1.back().time + v2.back().time < v.back().time)
        {
            ans += v1.back().time + v2.back().time;
            v1.pop_back();
            v2.pop_back();
        }
        else
        {
            ans += v.back().time;
            v.pop_back();
        }
        k--;
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