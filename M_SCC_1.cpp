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
void __print(stack<int> s)
{
    while (!s.empty())
    {
        cerr << s.top() << " ";
        s.pop();
    }
}
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

int n, e;
unordered_map<int, int> val;
unordered_map<int, vector<int>> adj, InvAdj;
stack<int> order;
unordered_map<int, bool> visited;
unordered_map<int, vector<int>> all_scc;
unordered_map<int, int> compId, compVal;
void dfs_for_start(int curr)
{
    visited[curr] = 1;
    for (auto i : adj[curr])
        if (!visited[i])
            dfs_for_start(i);
    order.push(curr);
}
vector<int> curr_comp;
void dfs_for_scc(int curr)
{
    visited[curr] = 1;
    for (auto i : InvAdj[curr])
        if (!visited[i])
            dfs_for_scc(i);
    curr_comp.push_back(curr);
}

inline void scc()
{
    cin >> n >> e;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        val[i] = x;
    }
    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        InvAdj[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
        if (!visited[i])
            dfs_for_start(i);
    visited.clear();
    while (!order.empty())
    {
        if (!visited[order.top()])
        {
            curr_comp.clear();
            dfs_for_scc(order.top());
            int sz = all_scc.size() + 1;
            all_scc[sz] = curr_comp;
            int temp = 0;
            for (auto i : curr_comp)
            {
                compId[i] = sz;
                temp += val[i];
            }
            compVal[sz] = temp;
        }
        order.pop();
    }
}

unordered_map<int, set<int>> scc_Graph;
unordered_map<int, bool> visited1;
vector<int> dp(100005, -1);
int dfs(int curr)
{
    if (dp[curr] != -1)
        return dp[curr];
    int ans = 0;
    visited1[curr] = 1;
    for (auto i : scc_Graph[curr])
    {
        ans = max(ans, dfs(i));
    }
    return dp[curr] = ans + compVal[curr];
}

inline void solve()
{
    scc();
    for (auto i : adj)
    {
        for (auto j : i.second)
        {
            if (compId[i.first] != compId[j])
            {
                scc_Graph[compId[i.first]].insert(compId[j]);
            }
        }
    }
    int ans = 0;
    for (auto i : all_scc)
    {
        if (!visited1[i.first])
            ans = max(ans, dfs(i.first));
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