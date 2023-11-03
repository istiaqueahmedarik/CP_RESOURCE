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
const int N = 2e5 + 5;
const int D = 19;
const int S = (1 << D);

int n, q, v[N];
vector<int> adj[N];

int sz[N], p[N], dep[N];
int st[S], id[N], tp[N];

void update(int idx, int val)
{
    st[idx += n] = val;
    for (idx /= 2; idx; idx /= 2)
        st[idx] = max(st[2 * idx], st[2 * idx + 1]);
}

int query(int lo, int hi)
{
    int ra = 0, rb = 0;
    for (lo += n, hi += n + 1; lo < hi; lo /= 2, hi /= 2)
    {
        if (lo & 1)
            ra = max(ra, st[lo++]);
        if (hi & 1)
            rb = max(rb, st[--hi]);
    }
    return max(ra, rb);
}

int dfs_sz(int cur, int par)
{
    sz[cur] = 1;
    p[cur] = par;
    for (int chi : adj[cur])
    {
        if (chi == par)
            continue;
        dep[chi] = dep[cur] + 1;
        p[chi] = cur;
        sz[cur] += dfs_sz(chi, cur);
    }
    return sz[cur];
}

int ct = 1;

void dfs_hld(int cur, int par, int top)
{
    id[cur] = ct++;
    tp[cur] = top;
    update(id[cur], v[cur]);
    int h_chi = -1, h_sz = -1;
    for (int chi : adj[cur])
    {
        if (chi == par)
            continue;
        if (sz[chi] > h_sz)
        {
            h_sz = sz[chi];
            h_chi = chi;
        }
    }
    if (h_chi == -1)
        return;
    dfs_hld(h_chi, cur, top);
    for (int chi : adj[cur])
    {
        if (chi == par || chi == h_chi)
            continue;
        dfs_hld(chi, cur, chi);
    }
}

int path(int x, int y)
{
    int ret = 0;
    while (tp[x] != tp[y])
    {
        if (dep[tp[x]] < dep[tp[y]])
            swap(x, y);
        ret = max(ret, query(id[tp[x]], id[x]));
        x = p[tp[x]];
    }
    if (dep[x] > dep[y])
        swap(x, y);
    ret = max(ret, query(id[x], id[y]));
    return ret;
}

inline void solve()
{
    int n, k, x;
    cin >> n >> x >> k;
    for (int i = 0; i <= n; i++)
        v[i] = 1;
    for (int i = 1; i <= n; i++)
    {
        adj[i].push_back(i / 2);
        adj[i / 2].push_back(i);
    }
    dfs_sz(1, 1);
    dfs_hld(1, 1, 1);
    int ans = 0;
    for (int i = 0; i <= n; i++)
    {
        int temp = path(i, x);
        if (temp == k)
            ans++;
    }
    cout << ans << endl;
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