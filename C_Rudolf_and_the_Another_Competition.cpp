#include <bits/stdc++.h>
#define int long long
#define float double
#define endl '\n'
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);

using namespace std;
bool comp(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b)
{
    if (a.first > b.first)
        return true;
    else if (a.first == b.first)
    {
        return a.second.second < b.second.second;
    }
    else
        return false;
}
int32_t main()
{
    IOS;
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, h;
        cin >> n >> m >> h;
        map<int, multiset<int>> Tij;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int x;
                cin >> x;
                Tij[i].insert(x);
            }
        }
        map<int, vector<int>> prefix;
        vector<pair<int, pair<int, int>>> score;
        for (auto i : Tij)
        {
            bool flag = true;
            for (auto j : i.second)
            {
                if (flag)
                {
                    flag = false;
                    prefix[i.first].push_back(j);
                }
                else
                {
                    prefix[i.first].push_back(j + prefix[i.first].back());
                }
            }
            int sc = 0;
            int pen = 0;
            for (int j = 0; j < prefix[i.first].size(); j++)
            {
                if (prefix[i.first][j] <= h)
                {
                    sc++;
                    pen += prefix[i.first][j];
                }
            }
            score.push_back({sc, {i.first, pen}});
        }
        sort(score.begin(), score.end(), comp);
        int ans = 0;
        for (int i = 0; i < score.size(); i++)
        {
            // cout << score[i].first << " " << score[i].second.first << " " << score[i].second.second << endl;
            if (score[i].second.first == 0)
            {
                ans = i + 1;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
/*
    n participant
    Rudolf = 1;
    m problems
    h min.
    t(i,j) ith participant time of jth problem
    ex:
    h = 120
    tIj = 20 15 110


*/