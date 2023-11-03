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

inline void solve()
{
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '1')
        {
            int three = find(all(s), '3') - s.begin();
            int seven = find(all(s), '7') - s.begin();
            int nine = find(all(s), '9') - s.begin();
            if (i < three)
            {
                cout << "13" << endl;
                return;
            }
            else if (i < seven)
            {
                cout << "17" << endl;
                return;
            }
            else if (i < nine)
            {
                cout << "19" << endl;
                return;
            }
        }
        else if (s[i] == '2')
        {
            int three = find(all(s), '3') - s.begin();
            int nine = find(all(s), '9') - s.begin();
            if (i < three)
            {
                cout << "23" << endl;
                return;
            }
            else if (i < nine)
            {
                cout << "29" << endl;
                return;
            }
        }
        else if (s[i] == '5')
        {
            int three = find(all(s), '3') - s.begin();
            int nine = find(all(s), '9') - s.begin();
            if (i < three)
            {
                cout << "53" << endl;
                return;
            }
            else if (i < nine)
            {
                cout << "59" << endl;
                return;
            }
        }
        else if (s[i] == '3')
        {
            int seven = find(all(s), '7') - s.begin();
            int one = find(all(s), '1') - s.begin();
            if (i < seven)
            {
                cout << "37" << endl;
                return;
            }
            else if (i < one)
            {
                cout << "31" << endl;
                return;
            }
        }
        else if (s[i] == '6')
        {
            int seven = find(all(s), '7') - s.begin();
            int one = find(all(s), '1') - s.begin();
            if (i < seven)
            {
                cout << "67" << endl;
                return;
            }
            else if (i < one)
            {
                cout << "61" << endl;
                return;
            }
        }
        else if (s[i] == '4')
        {
            int three = find(all(s), '3') - s.begin();
            int seven = find(all(s), '7') - s.begin();
            int one = find(all(s), '1') - s.begin();
            if (i < three)
            {
                cout << "43" << endl;
                return;
            }
            else if (i < seven)
            {
                cout << "47" << endl;
                return;
            }
            else if (i < one)
            {
                cout << "41" << endl;
                return;
            }
        }
        else if (s[i] == '7')
        {
            int three = find(all(s), '3') - s.begin();
            int nine = find(all(s), '9') - s.begin();
            int one = find(all(s), '1') - s.begin();
            if (i < three)
            {
                cout << "73" << endl;
                return;
            }
            else if (i < nine)
            {
                cout << "79" << endl;
                return;
            }
            else if (i < one)
            {
                cout << "71" << endl;
                return;
            }
        }
        else if (s[i] == '8')
        {
            int three = find(all(s), '3') - s.begin();
            int nine = find(all(s), '9') - s.begin();
            if (i < three)
            {
                cout << "83" << endl;
                return;
            }
            else if (i < nine)
            {
                cout << "89" << endl;
                return;
            }
        }
        else
        {
            int seven = find(all(s), '7') - s.begin();
            if (i < seven)
            {
                cout << "97" << endl;
                return;
            }
        }
    }
    cout << -1 << endl;
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