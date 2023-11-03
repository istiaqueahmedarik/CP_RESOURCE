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

    string a, b;
    cin >> a >> b;
    int aInd = a.size() - 1, bInd = b.size() - 1;
    while (a[aInd] == b[bInd])
    {
        aInd--;
        bInd--;
    }
    aInd = max(0LL, aInd + 1);
    bInd = max(0LL, bInd + 1);
    cout << aInd + bInd << endl;

    return 0;
}