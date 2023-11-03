#include <bits/stdc++.h>
#define int long long
#define float double
#define endl '\n'
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);

using namespace std;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int visited[100][100];
int grid[100][100];
int n, m;
int c = 0;
bool valid(int x, int y)
{
    return (x >= 0 && x < n && y >= 0 && y < m);
}
void dfs(int i, int j)
{
    visited[i][j] = 1;
    c++;
    for (int p = 0; p < 4; p++)
    {
        int tempx = i + dx[p];
        int tempy = j + dy[p];
        if (valid(tempx, tempy) && !visited[tempx][tempy] && grid[tempx][tempy] == 0)
        {
            dfs(tempx, tempy);
        }
    }
}
int32_t main()
{
    IOS;
    int t, cs = 1;
    cin >> t;
    while (t--)
    {
        cin >> m >> n;
        pair<int, int> src;
        for (int i = 0; i < n; i++)
        {

            for (int j = 0; j < m; j++)
            {
                grid[i][j] = 0;
                visited[i][j] = 0;
                c = 0;
            }
        }
        for (int i = 0; i < n; i++)
        {
            string s;
            cin >> s;
            for (int j = 0; j < m; j++)
            {
                if (s[j] == '#')
                    grid[i][j] = 1;
                else if (s[j] == '@')
                    src = {i, j};
            }
        }
        dfs(src.first, src.second);
        cout << "Case " << cs++ << ": " << c << endl;
    }

    return 0;
}