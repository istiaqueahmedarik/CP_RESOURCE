
#include <bits/stdc++.h>
#define int long long
#define float double
#define endl '\n'
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);

using namespace std;

int sum_of_all(vector<int> &v)
{
    int sum = 0;
    int ans = 0;
    for (int i = 0; i < v.size(); i++)
    {
        ans += i * v[i] - sum;
        sum += v[i];
    }
    return ans;
}

int32_t main()
{
    IOS;
    int n, m;
    cin >> n >> m;
    map<int, vector<int>> mpX;
    map<int, vector<int>> mpY;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            int x;
            cin >> x;
            mpX[x].push_back(i);
            mpY[x].push_back(j);
        }
    }
    int sum = 0;

    for (int i = 0; i < mpX.size(); i++)
    {
        sort(mpX[i].begin(), mpX[i].end());
        sort(mpY[i].begin(), mpY[i].end());
        sum += sum_of_all(mpX[i]) + sum_of_all(mpY[i]);
    }

    cout << sum << endl;
    return 0;
}
