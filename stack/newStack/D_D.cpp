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
    stack<int> st1;
    stack<int> temp;
    int curr = 1;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (x == curr)
        {
            curr++;
            cout << 1 << "\n"
                 << -1 << endl; // jodi serially ashe taile stack e dhukabo na
            continue;
        }

        st1.push(x); // eigulake serial kra lagbe tai dead end 1 e
        cout << 1 << endl;
    }
    while (!st1.empty() || !temp.empty())
    {
        while (!st1.empty())
        {
            if (st1.top() == curr)
            {
                curr++;
                cout << -1 << endl; // dead end 1 diye ber hoye jabe
            }
            else
            {
                temp.push(st1.top());
                cout << 12 << endl; // naile shift
            }
            st1.pop();
        }
        while (!temp.empty())
        {
            if (temp.top() == curr)
            {
                curr++;
                cout << -2 << endl;
            }
            else
            {
                st1.push(temp.top());
                cout << 21 << endl;
            }
            temp.pop();
        }
    }
    return 0;
}
/*
    a sroting station
    station has a input track
    output track
    and two dead end
    if a car x is the first car on the input track -> it can be move to any dead end
    if the car x is closest car to the exit
    then it can be moved to the output track
    Command 1->dead end 1
    Command 2->dead end 2
    Command -1 -> dead end 1 -> exit
    Command -2 -> dead end 2 -> exit
    Command 12-> dead end 1 -> dead end 2
    Command 21-> dead end 2 -> dead end 1
    output to dead end or dead end to input is not allowed
    dead end must need to used for input->output
*/