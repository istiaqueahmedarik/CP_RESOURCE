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
class LazySegmentTree
{
private:
    T n;
    vector<T> tree;
    vector<T> lazy;

    void build(vector<T> &arr, T v, T tl, T tr)
    {
        if (tl == tr)
        {
            tree[v] = arr[tl];
        }
        else
        {
            T tm = (tl + tr) / 2;
            build(arr, v * 2, tl, tm);
            build(arr, v * 2 + 1, tm + 1, tr);
            tree[v] = min(tree[v * 2], tree[v * 2 + 1]);
        }
    }

    void push(T v)
    {
        tree[v * 2] += lazy[v];
        tree[v * 2 + 1] += lazy[v];
        lazy[v * 2] += lazy[v];
        lazy[v * 2 + 1] += lazy[v];
        lazy[v] = 0;
    }

    void update(T v, T tl, T tr, T l, T r, T val)
    {
        if (l > r)
            return;
        if (l == tl && r == tr)
        {
            tree[v] += val;
            lazy[v] += val;
        }
        else
        {
            push(v);
            int tm = (tl + tr) / 2;
            update(v * 2, tl, tm, l, min(r, tm), val);
            update(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, val);
            tree[v] = min(tree[v * 2], tree[v * 2 + 1]);
        }
    }

    T query(T v, T tl, T tr, T l, T r)
    {
        if (l > r)
            return numeric_limits<T>::max();
        if (l <= tl && tr <= r)
        {
            return tree[v];
        }
        else
        {
            push(v);
            T tm = (tl + tr) / 2;
            T left_min = query(v * 2, tl, tm, l, min(r, tm));
            T right_min = query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
            return min(left_min, right_min);
        }
    }

public:
    LazySegmentTree(vector<T> &arr)
    {
        n = arr.size();
        tree.resize(4 * n);
        lazy.resize(4 * n);
        build(arr, 1, 0, n - 1);
    }

    void updateRange(T l, T r, T val)
    {
        update(1, 0, n - 1, l, r, val);
    }

    T queryRange(T l, T r)
    {
        return query(1, 0, n - 1, l, r);
    }
};

inline void solve()
{
    int n, q;
    cin >> n;
    vector<int> arr(n + 1, 0);
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    LazySegmentTree<int> st(arr);
    cin >> q;
    while (q--)
    {
        string s;
        getline(cin >> ws, s);
        if (count(all(s), ' ') == 2)
        {
            int l, r, v;
            l = stoi(s.substr(0, s.find(' ')));
            s.erase(0, s.find(' ') + 1);
            r = stoi(s.substr(0, s.find(' ')));
            s.erase(0, s.find(' ') + 1);
            v = stoi(s);
            l++;
            r++;
            if (l > r)
            {
                st.updateRange(l, n, v);
                st.updateRange(1, r, v);
            }
            else
                st.updateRange(l, r, v);
        }
        else
        {

            int l, r;
            l = stoi(s.substr(0, s.find(' ')));
            s.erase(0, s.find(' ') + 1);
            r = stoi(s);
            l++;
            r++;
            if (l > r)
                cout << min(st.queryRange(l, n), st.queryRange(1, r)) << endl;
            else
                cout << st.queryRange(l, r) << endl;
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