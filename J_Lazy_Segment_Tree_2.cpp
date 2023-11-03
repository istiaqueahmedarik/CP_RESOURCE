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
template <typename T>
class LazySegmentTree
{
public:
    LazySegmentTree(int n) : n(n), tree(4 * n, 0), lazy(4 * n, -1) {}

    void updateRange(int left, int right, T value)
    {
        updateRange(0, 0, n - 1, left, right, value);
    }

    T query(int left, int right)
    {
        return query(0, 0, n - 1, left, right);
    }

private:
    int n;
    std::vector<T> tree;
    std::vector<T> lazy;

    void updateRange(int node, int segLeft, int segRight, int updateLeft, int updateRight, T value)
    {
        if (lazy[node] != -1)
        {
            tree[node] = lazy[node] * (segRight - segLeft + 1);
            if (segLeft != segRight)
            {
                lazy[2 * node + 1] = lazy[node];
                lazy[2 * node + 2] = lazy[node];
            }
            lazy[node] = -1;
        }

        if (segRight < updateLeft || segLeft > updateRight)
        {
            return;
        }

        if (updateLeft <= segLeft && segRight <= updateRight)
        {
            tree[node] = value * (segRight - segLeft + 1);
            if (segLeft != segRight)
            {
                lazy[2 * node + 1] = value;
                lazy[2 * node + 2] = value;
            }
            return;
        }

        int mid = (segLeft + segRight) / 2;
        updateRange(2 * node + 1, segLeft, mid, updateLeft, updateRight, value);
        updateRange(2 * node + 2, mid + 1, segRight, updateLeft, updateRight, value);
        tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
    }

    T query(int node, int segLeft, int segRight, int queryLeft, int queryRight)
    {
        if (lazy[node] != -1)
        {
            tree[node] = lazy[node] * (segRight - segLeft + 1);
            if (segLeft != segRight)
            {
                lazy[2 * node + 1] = lazy[node];
                lazy[2 * node + 2] = lazy[node];
            }
            lazy[node] = -1;
        }

        if (segRight < queryLeft || segLeft > queryRight)
        {
            return 0;
        }

        if (queryLeft <= segLeft && segRight <= queryRight)
        {
            return tree[node];
        }

        int mid = (segLeft + segRight) / 2;
        T leftResult = query(2 * node + 1, segLeft, mid, queryLeft, queryRight);
        T rightResult = query(2 * node + 2, mid + 1, segRight, queryLeft, queryRight);
        return leftResult + rightResult;
    }
};

inline void solve()
{
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    vector<int> a(n + 1, 0);
    LazySegmentTree<int> seg(n + 1);
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        int x;
        cin >> x;
        seg.updateRange(l, r, x);
    }
    for (int i = 1; i <= n; i++)
    {
        cout << seg.query(i, i) << " ";
    }
    cout << endl;
    int curInd = 1;
    while (1)
    {
        int cur = seg.query(curInd, curInd);
        string sub;
        while (curInd <= n && seg.query(curInd, curInd) == cur)
        {
            sub += s[curInd - 1];
            curInd++;
        }
        if (cur == 0)
            sort(rall(sub));
        else
            sort(all(sub));
        cout << sub;
        if (curInd > n)
            break;
    }
}

auto main() -> int32_t
{
    IOS;
    int t = 1, cs = 1;
    //  cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}