#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> ans;
// using recursion
void generate(vector<int> &main, vector<int> &temp, int i)
{
    if (i == main.size())
    {
        ans.push_back(temp);
        return;
    }
    // take
    temp.push_back(main[i]);
    generate(main, temp, i + 1);
    // not take
    temp.pop_back();
    generate(main, temp, i + 1);
}

// using bit manipulation
void Generate(vector<int> &main)
{
    int n = main.size();
    for (int i = 0; i < (1 << n); i++)
    {
        vector<int> temp;
        for (int j = 0; j < n; j++)
        {
            if (i & (1 << j))
            {
                temp.push_back(main[j]);
            }
        }
        ans.push_back(temp);
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector<int> temp = {};
    generate(arr, temp, 0);
    for (auto i : ans)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    ans.clear();
    Generate(arr);
    for (auto i : ans)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}