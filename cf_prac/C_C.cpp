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
    int low = 0, high = 1000000;
    string s;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        cout << mid << endl;
        cout.flush();
        cin >> s;
        if (s == "Bigger")
        {
            low = mid + 1;
        }
        else if (s == "Smaller")
        {
            high = mid - 1;
        }
        else
        {
            break;
        }
    }

    return 0;
}