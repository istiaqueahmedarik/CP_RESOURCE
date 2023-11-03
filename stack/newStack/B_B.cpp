#include <bits/stdc++.h>
#define int long long
#define float double
#define endl '\n'
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);

using namespace std;
int32_t main()
{
    IOS;
    int n;
    cin >> n;
    int p;
    cin >> p;
    queue<int> q;
    for (int i = 0; i < p; i++)
    {
        int x;
        cin >> x;
        q.push(x);
    }
    int k;
    cin >> k;
    queue<int> q1;
    for (int i = 0; i < k; i++)
    {
        int x;
        cin >> x;
        q1.push(x);
    }
    int mx = 10000;
    int c = 0;
    while (mx--)
    {
        if (q.empty())
        {
            cout << c << " " << 2 << endl;
            return 0;
        }
        if (q1.empty())
        {
            cout << c << " " << 1 << endl;
            return 0;
        }
        c++;
        int x = q.front();
        int y = q1.front();
        q.pop();
        q1.pop();
        if (x > y)
        {
            q.push(y);
            q.push(x);
        }
        else
        {
            q1.push(x);
            q1.push(y);
        }
    }
    cout << -1 << endl;

    return 0;
}
/*
    two board soldier is playing
    n card
    1->n
    distinct value
    they divide the cards can be unequally
    int each fight
    two will place top of his card on the table
    the one with higher value wins
    the winner takes both cards
    if stack is empty game stop
    how many fights will be there or infinity
*/