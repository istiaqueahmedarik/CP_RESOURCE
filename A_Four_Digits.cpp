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
    string s;
    cin >> s;
    int n = s.size();
    int x = 4 - n;
    string ans;
    for (int i = 0; i < x; i++)
        ans += '0';
    cout << ans + s << endl;
    return 0;
}