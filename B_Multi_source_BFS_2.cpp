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
const int MOD = 1e9 + 7, dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};
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

int n, m;

vector<vector<char>> grid;
queue<pair<int, int>> q;
vector<vector<int>> level, level1;
vector<vector<bool>> vis, vis1;
pair<int, int> src;
stack<char> ans;
inline void solve()
{
    cin >> n >> m;
    grid.resize(n, vector<char>(m));
    level.resize(n, vector<int>(m, LLONG_MAX));
    level1.resize(n, vector<int>(m, 0));
    vis.resize(n, vector<bool>(m, false));
    vis1.resize(n, vector<bool>(m, false));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
            if (grid[i][j] == 'A')
                src = {i, j};
            if (grid[i][j] == 'M')
            {
                q.push({i, j});
                level[i][j] = 0;
                vis[i][j] = true;
            }
        }
    }
    if (!q.empty())
        vis[q.front().first][q.front().second] = true;
    while (!q.empty())
    {
        pair<int, int> curr = q.front();
        q.pop();
        int x = curr.first, y = curr.second;
        for (int i = 0; i < 4; i++)
        {
            int tempX = x + dx[i], tempY = y + dy[i];
            if (tempX >= 0 && tempX < n && tempY >= 0 && tempY < m && !vis[tempX][tempY] && grid[tempX][tempY] != '#')
            {
                q.push({tempX, tempY});
                vis[tempX][tempY] = true;
                if (level[x][y] == LLONG_MAX)
                    level[x][y] = 0;
                level[tempX][tempY] = level[x][y] + 1;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            vis[i][j] = false;
    }
    q.push(src);
    vis[src.first][src.second] = true;
    map<pair<int, int>, pair<int, int>> parent;
    parent[src] = src;
    if (src.first == 0 || src.first == n - 1 || src.second == 0 || src.second == m - 1)
    {
        cout << "YES\n0\n";
        return;
    }
    pair<int, int> ans = {-1, -1};
    while (!q.empty())
    {
        pair<int, int> curr = q.front();
        q.pop();
        int x = curr.first, y = curr.second;
        for (int i = 0; i < 4; i++)
        {
            int tempX = x + dx[i], tempY = y + dy[i];
            if (tempX >= 0 && tempX < n && tempY >= 0 && tempY < m && !vis[tempX][tempY] && grid[tempX][tempY] != '#' && level1[x][y] + 1 < level[tempX][tempY])
            {
                q.push({tempX, tempY});
                vis[tempX][tempY] = true;
                level1[tempX][tempY] = level1[x][y] + 1;
                parent[{tempX, tempY}] = {x, y};
                if (tempX == 0 || tempX == n - 1 || tempY == 0 || tempY == m - 1)
                {
                    ans = {tempX, tempY};
                    break;
                }
            }
        }
    }
    if (ans.first == -1)
    {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    stack<char> path;
    while (parent[ans] != ans)
    {
        debug(ans);
        pair<int, int> diff = {ans.first - parent[ans].first, ans.second - parent[ans].second};
        if (diff.first == 0 && diff.second == 0)
            break;
        if (diff.first == 0 && diff.second == 1)
        {
            path.push('R');
        }
        else if (diff.first == 0 && diff.second == -1)
        {
            path.push('L');
        }
        else if (diff.first == 1 && diff.second == 0)
        {
            path.push('D');
        }
        else if (diff.first == -1 && diff.second == 0)
            path.push('U');
        ans = parent[ans];
    }
    cout << path.size() << endl;
    while (!path.empty())
    {
        cout << path.top();
        path.pop();
    }
    cout << endl;
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < m; j++)
    //     {
    //         if (level[i][j] == LLONG_MAX)
    //             cout << "i"
    //                  << " ";
    //         else
    //             cout << level[i][j] << "(" << level1[i][j] << ")"
    //                  << " ";
    //     }
    //     cout << endl;
    // }
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