#include <bits/stdc++.h>
// #define int long long
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
    int t;
    cin >> t;
    while (t--)
    {
        multiset<int> sLeft;
        multiset<int> sRight;
        int n = 1;
        while (1)
        {
            cin >> n;
            if (!n)
                break;
            if (n == -1)
            {
                // cout << "sLeft: ";
                // for (auto i : sLeft)
                //     cout << i << " ";
                // cout << endl;
                // cout << "sRight: ";
                // for (auto i : sRight)
                //     cout << i << " ";
                // cout << endl;
                if (sLeft.empty())
                    continue;
                else
                {
                    if (sLeft.size() >= sRight.size())
                    {
                        cout << *sLeft.rbegin() << endl;
                        sLeft.erase(sLeft.find(*sLeft.rbegin()));
                    }

                    else
                    {
                        cout << *sRight.begin() << endl;
                        sRight.erase(sRight.find(*sRight.begin()));
                    }
                    // cout << "sLeft: ";
                    // for (auto i : sLeft)
                    //     cout << i << " ";
                    // cout << endl;
                    // cout << "sRight: ";
                    // for (auto i : sRight)
                    //     cout << i << " ";
                    // cout << endl;
                    int diff = sLeft.size() - sRight.size();
                    // cout << "diff: " << diff << " sLeft.size() " << sLeft.size() << " sRight: " << sRight.size() << endl;
                    if (diff > 1)
                    {
                        sRight.insert(*sLeft.rbegin());
                        sLeft.erase(sLeft.find(*sLeft.rbegin()));
                    }
                    else if (diff < -1)
                    {
                        sLeft.insert(*sRight.begin());
                        sRight.erase(sRight.find(*sRight.begin()));
                    }
                }
            }
            else if (n > 0)
            {
                // cout << "sLeftBefore: ";
                // for (auto i : sLeft)
                //     cout << i << " ";
                // cout << endl;
                // cout << "sRightBefore: ";
                // for (auto i : sRight)
                //     cout << i << " ";
                // cout << endl;
                if (sLeft.empty() || n <= *sLeft.rbegin())
                    sLeft.insert(n);
                else
                    sRight.insert(n);

                int diff = sLeft.size() - sRight.size();
                if (diff > 1)
                {
                    sRight.insert(*sLeft.rbegin());
                    sLeft.erase(sLeft.find(*sLeft.rbegin()));
                }
                else if (diff < -1)
                {
                    sLeft.insert(*sRight.begin());
                    sRight.erase(sRight.find(*sRight.begin()));
                }
                //     cout << "sLeft: ";
                //     for (auto i : sLeft)
                //         cout << i << " ";
                //     cout << endl;
                //     cout << "sRight: ";
                //     for (auto i : sRight)
                //         cout << i << " ";
                //     cout << endl;
                // }
            }
        }
        return 0;
    }
}