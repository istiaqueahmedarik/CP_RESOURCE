#include <bits/stdc++.h>
#define int long long
#define float double
#define endl '\n'
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);

using namespace std;
char grid[40][40];
bool checker(int i, int j)
{
    char check = grid[i][j];
    if (check == '.')
        return false;
    if (grid[i][j] == grid[i][j + 1] && grid[i][j] == grid[i][j + 2])
    {
        return true;
    }
    if (grid[i][j] == grid[i][j - 1] && grid[i][j] == grid[i][j - 2])
    {
        return true;
    }
    if (grid[i][j] == grid[i - 1][j] && grid[i][j] == grid[i - 2][j])
    {
        return true;
    }
    if (grid[i][j] == grid[i + 1][j] && grid[i][j] == grid[i + 2][j])
    {

        return true;
    }
    if (check == grid[i + 1][j + 1] && check == grid[i + 2][j + 2])
    {

        return true;
    }
    if (check == grid[i + 1][j - 1] && check == grid[i + 2][j - 2])
    {

        return true;
    }
    return false;
}
void reset()
{
    for (int i = 0; i < 40; i++)
    {
        for (int j = 0; j < 40; j++)
        {
            grid[i][j] = '.';
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
        reset();
        for (int i = 4; i <= 6; i++)
        {
            for (int j = 4; j <= 6; j++)
            {
                cin >> grid[i][j];
            }
        }
        char ans = '.';
        for (int i = 4; i <= 6; i++)
        {
            for (int j = 4; j <= 6; j++)
            {
                if (checker(i, j))
                {
                    ans = grid[i][j];
                    break;
                }
            }
        }
        if (ans == '.')
            cout << "DRAW" << endl;
        else
            cout << ans << endl;
    }
    return 0;
}