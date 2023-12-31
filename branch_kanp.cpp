#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> arr;
int upperBound(int n, int MyCurProf, int curInd, int kanpW)
{
    if (curInd + 1 == n)
        return MyCurProf;
    return MyCurProf + (kanpW - arr[curInd].first) * (arr[curInd + 1].second / arr[curInd + 1].first);
}

int knapSack(int n, int kanpW)
{
    queue<pair<int, int>> q;
    q.push({0, 0});
    int ans = 0;
    while (!q.empty())
    {
        int curInd = q.front().first;
        int MyCurProf = q.front().second;
        q.pop();
        if (curInd == n)
        {
            ans = max(ans, MyCurProf);
            continue;
        }
        int bound_val = upperBound(n, MyCurProf, curInd, kanpW);
        if (bound_val <= ans)
        {
            continue;
        }
        q.push({curInd + 1, MyCurProf});                      // not taking the item
        q.push({curInd + 1, MyCurProf + arr[curInd].second}); // taking the item
    }
    return ans;
}

int main()
{
    int n, kanpW;
    cin >> n >> kanpW;
    for (int i = 0; i < n; i++)
    {
        int w, p;
        cin >> w >> p;
        arr.push_back({w, p});
    }
    sort(arr.begin(), arr.end());
    cout << knapSack(n, kanpW);
    return 0;
}