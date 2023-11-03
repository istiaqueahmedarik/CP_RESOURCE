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
    priority_queue<int> pq;
    pq.push(1);
    pq.push(2);
    pq.push(3);
    while (!pq.empty())
    {
        cout << pq.top() << endl;
        pq.pop();
    }
    return 0;
}