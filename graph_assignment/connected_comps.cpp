#include <bits/stdc++.h>
using namespace std;
int visited[1000][1000];
char grid[1000][1000];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int n, m;
bool isValid(int x, int y)
{
    if (x < 0 || x >= n || y < 0 || y >= m)
    {
        return false;
    }
    if (grid[x][y] == '#')
    {
        return false;
    }
    return true;
}

int mx_len = -1;
int c = 0;
int dfs(int x, int y)
{
    visited[x][y] = 1;
    c++;
    for (int i = 0; i < 4; i++)
    {
        int new_x = x + dx[i];
        int new_y = y + dy[i];
        if (isValid(new_x, new_y) && !visited[new_x][new_y])
        {
            dfs(new_x, new_y);
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == '.' && !visited[i][j])
            {
                dfs(i, j);
                mx_len = max(mx_len, c);
                c = 0;
                ans++;
            }
        }
    }
    cout << "Rooms - " << ans << endl;
    cout << "Length of the longest room - " << mx_len << endl;

    return 0;
}