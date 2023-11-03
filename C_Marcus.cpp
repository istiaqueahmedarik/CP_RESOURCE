#include <bits/stdc++.h>
#define int long long
#define float double
#define endl '\n'
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);

using namespace std;
int n, m;
int dx[] = {0, -1, 0};
int dy[] = {-1, 0, 1};
int grid[10][10];
char gridChar[10][10];
int visited[10][10];
char states[] = {'I', 'E', 'H', 'O', 'V', 'A', '#'};
int now = 0;
bool isValid(int i, int j)
{
    return (i >= 0 && i < n && j >= 0 && j < m && grid[i][j] == 1 && gridChar[i][j] == states[now]);
}
void dfs(int x, int y)
{
    visited[x][y] = 1;
    // cout << x << " " << y << endl;
    for (int i = 0; i < 3; i++)
    {
        int tempX = x + dx[i];
        int tempY = y + dy[i];

        if (isValid(tempX, tempY) && !visited[tempX][tempY])
        {
            now++;
            // cout << tempX << " " << tempY << " " << grid[tempX][tempY] << endl;
            if (i == 0)
            {
                cout << "left";
            }
            else if (i == 1)
            {
                cout << "forth";
            }
            else if (i == 2)
            {
                cout << "right";
            }
            if (gridChar[tempX][tempY] != '#')
                cout << ' ';
            dfs(tempX, tempY);
        }
    }
}
int32_t main()
{
    IOS;
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        pair<int, int> src;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                grid[i][j] = 0;
                gridChar[i][j] = ' ';
                now = 0;
                visited[i][j] = 0;
            }
        }
        for (int i = 0; i < n; i++)
        {
            string s;
            cin >> s;
            for (int j = 0; j < m; j++)
            {
                gridChar[i][j] = s[j];
                if (s[j] == 'I' || s[j] == 'E' || s[j] == 'H' || s[j] == 'O' || s[j] == 'V' || s[j] == 'A' || s[j] == '#')
                {
                    grid[i][j] = 1;
                }
                else if (s[j] == '@')
                {
                    src = {i, j};
                }
            }
        }
        // cout << src.first << " " << src.second << endl;
        // for (int i = 0; i < n; i++)
        // {
        //     for (int j = 0; j < m; j++)
        //     {
        //         cout << gridChar[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        // cout << endl;
        dfs(src.first, src.second);
        cout << endl;
    }
    return 0;
}