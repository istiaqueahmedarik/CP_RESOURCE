/*******************************************
 |I|s|t|i|a|q|u|e| |A|h|m|e|d| |A|r|i|k|
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
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
#define FileIO                        \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout)
/// decltype and const
const int MOD = 1e9 + 7, dx[] = {1, 0, -1, 0, 1, -1, -1, 1}, dy[] = {0, 1, 0, -1, 1, 1, -1, -1};
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
// template <typename T>
// using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// template <typename T>
// using o_set_g = tree<T, null_type, greater<T>, rb_tree_tag, tree_order_statistics_node_update>;
// template <typename T>
// using o_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
// template <typename T>
// using o_multiset_g = tree<T, null_type, greater_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

void solve(int t)
{
    int n;
    cin >> n;
    vector<int> arr;
    for (int i = 0; i < n - 1; i++)
    {
        int x;
        cin >> x;
        arr.emplace_back(x);
    }
    set<int> s;
    map<int, int> visited;
    map<int, bool> cpy;
    for (int i = 0; i < n - 2; i++)
    {
        if (visited[abs(arr[i] - arr[i + 1])])
            cpy[abs(arr[i] - arr[i + 1])] = 1;
        visited[abs(arr[i] - arr[i + 1])] = 1;
        s.insert(abs(arr[i] - arr[i + 1]));
    }
    vector<int> v;
    map<int, int> mp;
    for (int i = 1; i <= n; i++)
        mp[i] = 1;
    for (auto i : s)
    {
        if (i > n)
            v.push_back(i);
        if (i <= n)
            mp[i] = 0;
    }
    mp[arr[0]] = 0;
    debug(v.size());
    debug(s);
    debug(v);

    int sm = 0;
    vector<int> missing;
    for (auto i : mp)
        if (i.second)
        {
            sm += i.first;
            missing.push_back(i.first);
        }
    debug(mp);
    // if (t == 411)
    // {

    //     string temp;
    //     for (auto i : arr)
    //     {
    //         temp += to_string(i);
    //         temp += "_";
    //     }
    //     cout << temp << endl;
    //     return;
    // }
    if (missing.size() > 2)
    {
        cout << "NO" << endl;
        return;
    }
    if (missing.size() == 1)
    {
        cout << "YES" << endl;

        return;
    }
    if (cpy.size() >= 2)
    {
        cout << "NO" << endl;
        return;
    }
    if (missing.size() == 2 && (missing[0] + missing[1] == arr[0] || cpy[missing[0] + missing[1]]))
    {
        cpy.erase(missing[0] + missing[1]);
        debug(cpy.size());
        if (cpy.size() >= 1 || v.size() >= 1)
        {
            cout << "NO" << endl;
            return;
        }
        cout << "YES" << endl;

        return;
    }
    if (missing.size() == 2 && !(cpy[missing[0] + missing[1]]))
    {
        cpy.erase(missing[0] + missing[1]);
    }
    debug(cpy);
    if (cpy.size() >= 1)
    {
        cout << "NO" << endl;
        return;
    }
    if (v.size() > 1 || v.size() == 0)
    {
        cout << "NO" << endl;
        return;
    }
    if (v[0] == sm)
    {

        cout << "YES" << endl;
        return;
    }
    else
        cout << "NO" << endl;
}

auto main() -> int32_t
{
    IOS;
    int t, cs = 1;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        solve(i);
    }

    return 0;
}
/*
    2 6 10 15
    2 6 7 10 15
    2 4 1 3 5

*/