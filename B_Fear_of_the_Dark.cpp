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
bool check(pair<int, int> circle1, pair<int, int> circle2, long double possible_radius, pair<int, int> point)
{
    long double distFromZerCircl1 = sqrt((circle1.first - 0) * (circle1.first - 0) + (circle1.second - 0) * (circle1.second - 0));
    long double distFromZerCircl2 = sqrt((circle2.first - 0) * (circle2.first - 0) + (circle2.second - 0) * (circle2.second - 0));
    long double distFromPointCircl1 = sqrt((circle1.first - point.first) * (circle1.first - point.first) + (circle1.second - point.second) * (circle1.second - point.second));
    long double distFromPointCircl2 = sqrt((circle2.first - point.first) * (circle2.first - point.first) + (circle2.second - point.second) * (circle2.second - point.second));
    long double distFromCircl1Circl2 = sqrt((circle1.first - circle2.first) * (circle1.first - circle2.first) + (circle1.second - circle2.second) * (circle1.second - circle2.second));

    if (distFromZerCircl1 <= possible_radius && distFromPointCircl1 <= possible_radius)
        return true;
    if (distFromZerCircl2 <= possible_radius && distFromPointCircl2 <= possible_radius)
        return true;
    if (distFromZerCircl1 <= possible_radius && distFromPointCircl2 <= possible_radius && distFromCircl1Circl2 <= 2 * possible_radius)
        return true;
    if (distFromZerCircl2 <= possible_radius && distFromPointCircl1 <= possible_radius && distFromCircl1Circl2 <= 2 * possible_radius)
        return true;
    return false;
}
inline void solve()
{
    int px, py, ax, ay, bx, by;
    cin >> px >> py >> ax >> ay >> bx >> by;
    pair<int, int> point = {px, py};
    pair<int, int> circle1 = {ax, ay};
    pair<int, int> circle2 = {bx, by};
    long double low = 0, high = (long double)1e18, ans;
    while (high - low > 1e-7)
    {
        long double mid = low + (high - low) / 2;
        if (check(circle1, circle2, mid, point))
        {
            ans = mid;
            high = mid;
        }
        else
            low = mid;
    }
    cout << fixed << setprecision(10) << ans << endl;
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