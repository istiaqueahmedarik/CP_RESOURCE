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
int dp[500][500];
int par[500][500];
int ans(vector<pair<int, int>> &mats, int left, int right)
{
    if (left >= right)
        return 0;
    if (dp[left][right] != -1)
        return dp[left][right];
    int mnCost = LLONG_MAX;
    for (int j = left; j < right; j++)
    {
        int l = ans(mats, left, j);
        int r = ans(mats, j + 1, right);
        if (mnCost > l + r + mats[left].first * mats[j].second * mats[right].second)
        {
            mnCost = l + r + mats[left].first * mats[j].second * mats[right].second;
            par[left][right] = j;
        }
    }
    mnCost = mnCost == LLONG_MAX ? 0 : mnCost;
    return dp[left][right] = mnCost;
}
void print(int left, int right)
{
    if (left == right)
    {
        cout << "A" << left << " ";
        return;
    }
    cout << "(";
    print(left, par[left][right]);
    print(par[left][right] + 1, right);
    cout << ")";
}

inline void solve()
{
    memset(dp, -1, sizeof dp);
    int n;
    cin >> n;
    vector<pair<int, int>> mat;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        mat.emplace_back(x, y);
    }
    cout << ans(mat, 0, n - 1) << endl;
    print(0, n - 1);
}

auto main() -> int32_t
{
    IOS;
    int t = 1, cs = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}