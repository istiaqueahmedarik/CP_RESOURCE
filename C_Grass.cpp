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

bool isInMiddle(pair<long double, long double> left, pair<long double, long double> right, pair<long double, long double> mid)
{
    if ((left.first <= mid.first && mid.first <= right.first) || (left.first >= mid.first && mid.first >= right.first))
    {
        if ((left.second <= mid.second && mid.second <= right.second) || (left.second >= mid.second && mid.second >= right.second))
        {
            return true;
        }
    }
    return false;
}

inline void solve()
{
    int n;
    cin >> n;
    vector<pair<long double, long double>> v(n);
    for (auto &i : v)
        cin >> i.first >> i.second;
    map<pair<long double, long double>, map<long double, vector<pair<long double, long double>>>> mp;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                continue;
            pair<long double, long double> first = v[i], second = v[j];
            long double slope = (long double)(first.second - second.second) / (first.first - second.first);
            mp[first][slope].push_back(second);
        }
    }
    for (auto i : v)
    {
        debug(i);
        for (auto j : mp[i])
        {
            debug(j.first, j.second);
        }
        if (mp[i].size() != 0)
        {
            vector<pair<long double, long double>> temp;
            temp.push_back(i);
            for (auto j : mp[i])
            {
                vector<pair<long double, long double>> temp2 = j.second;
                for (int k = 0; k < temp2.size(); k++)
                {
                    for (int l = k + 1; l < temp2.size(); l++)
                    {
                        if (isInMiddle(temp2[k], temp2[l], i))
                        {
                            temp.push_back(temp2[k]);
                            temp.push_back(temp2[l]);
                        }
                    }
                }
            }
            debug(temp);
            if (temp.size() >= 5)
            {
                cout << "YES\n";
                for (int m = 0; m < 5; m++)
                {
                    cout << temp[m].first << " " << temp[m].second << endl;
                }
                return;
            }
        }
    }
    cout << "NO\n";
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