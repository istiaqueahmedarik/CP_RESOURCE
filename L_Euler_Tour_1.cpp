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

template <class T>
class SegmentTree
{
    vector<T> arr, tree;

public:
    SegmentTree(vector<T> &arr)
    {
        this->arr.resize(arr.size());
        this->arr = arr;
        tree.resize(4 * arr.size());
    }
    void build(int node, int start, int end)
    {
        if (start == end)
        {
            tree[node] = arr[start];
            return;
        }
        build(node << 1, start, (start + end) >> 1);
        build((node << 1) + 1, ((start + end) >> 1) + 1, end);
        tree[node] = tree[node << 1] + tree[(node << 1) + 1];
    }
    void update(int node, int start, int end, int idx, T val)
    {
        if (start == end)
        {
            arr[idx] = tree[node] = val;
            return;
        }
        if (idx <= (start + end) >> 1)
            update(node << 1, start, (start + end) >> 1, idx, val);
        else
            update((node << 1) + 1, ((start + end) >> 1) + 1, end, idx, val);
        tree[node] = tree[node << 1] + tree[(node << 1) + 1];
    }
    //[l,r]
    T query(int node, int start, int end, int l, int r)
    {
        if (r < start || end < l)
            return 0;
        return (l <= start && end <= r) ? tree[node] : query(node << 1, start, (start + end) >> 1, l, r) + query((node << 1) + 1, ((start + end) >> 1) + 1, end, l, r);
    }
};

unordered_map<int, vector<int>> adj;
unordered_map<int, bool> visited;
unordered_map<int, int> Start, End, Val;
unordered_map<int, pair<int, int>> Range;
int start = 0;
void dfs(int node)
{
    visited[node] = true;
    Start[node] = start++;
    for (auto child : adj[node])
    {
        if (!visited[child])
            dfs(child);
    }
    End[node] = start - 1;
}
inline void solve()
{
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        Val[i + 1] = x;
    }
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1);
    vector<int> FlatArray(start + 5);
    for (auto i : Start)
    {
        FlatArray[i.second] = Val[i.first];
        Range[i.first] = {i.second, End[i.first]};
    }
    SegmentTree<int> st(FlatArray);
    st.build(1, 0, FlatArray.size() - 1);
    while (q--)
    {
        int x;
        cin >> x;
        if (x == 1)
        {
            int s, t;
            cin >> s >> t;
            int idx = Start[s];
            Val[s] = t;
            st.update(1, 0, FlatArray.size() - 1, idx, t);
        }
        else
        {
            int s;
            cin >> s;
            int l = Range[s].first, r = Range[s].second;
            int ans = st.query(1, 0, FlatArray.size() - 1, l, r);
            cout << ans << endl;
        }
    }
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