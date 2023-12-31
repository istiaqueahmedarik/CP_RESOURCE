#include <bits/stdc++.h>
using namespace std;

bool is_square(int n)
{
    int root = round(sqrt(n));
    return n == root * root;
}

void solve(int n)
{
    string digits = "123456789";
    map<set<int>, set<string>> m;
    do
    {
        string permutation = digits.substr(0, n);
        int num = stoi(permutation);
        if (is_square(num))
        {
            set<int> tmp;
            for (int i = 0; i < n; i++)
            {
                tmp.insert(permutation[i] - '0');
            }
            m[tmp].insert(permutation);
        }
    } while (next_permutation(digits.begin(), digits.end()));
    for (auto i : m)
    {
        if (i.second.size() == n)
        {
            for (auto j : i.second)
            {
                cout << j << endl;
            }
            return;
        }
    }
    cout << -1 << endl;
}

int main()
{
    solve(100);
    return 0;
}